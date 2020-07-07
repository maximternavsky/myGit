/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2015, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
 /* <DESC>
  * �������� ���-��������, ������� ��������� � ������� ���������� libxml.
  * </DESC>
  */
  // Written by Lars Nilsson
  //
  // ��������� �� ���������� ��������� ������ ����������� GNU C++:
  //
  // g++ -Wall -I/opt/curl/include -I/opt/libxml/include/libxml2 htmltitle.cpp \ 
  // -o htmltitle -L/opt/curl/lib -L/opt/libxml/lib -lcurl -lxml2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <curl/curl.h>
#include <libxml/HTMLparser.h>

//
//  ������������������� ��������� �����
//

#ifdef _MSC_VER
#define COMPARE(a, b) (!stricmp((a), (b)))
#else
#define COMPARE(a, b) (!strcasecmp((a), (b)))
#endif

//
//  ��������� ��������� ������� libxml
//

struct Context
{
    Context() : addTitle(false) { }

    bool addTitle;
    std::string title;
};

//
//  libcurl: ���������� ��� ������ ������ � ������������ ������

static char errorBuffer[CURL_ERROR_SIZE];
static std::string buffer;

//
//  libcurl: ������ ������ ������
//

static int writer(char* data, size_t size, size_t nmemb,
    std::string* writerData)
{
    if (writerData == NULL)
        return 0;

    writerData->append(data, size * nmemb);

    return size * nmemb;
}

//
//  libcurl: ������������� ����������
//

static bool init(CURL*& conn, char* url)
{
    CURLcode code;

    conn = curl_easy_init();

    if (conn == NULL)
    {
        fprintf(stderr, "Failed to create CURL connection\n");

        exit(EXIT_FAILURE);
    }

    code = curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer);
    if (code != CURLE_OK)
    {
        fprintf(stderr, "Failed to set error buffer [%d]\n", code);

        return false;
    }

    code = curl_easy_setopt(conn, CURLOPT_URL, url);
    if (code != CURLE_OK)
    {
        fprintf(stderr, "Failed to set URL [%s]\n", errorBuffer);

        return false;
    }

    code = curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
    if (code != CURLE_OK)
    {
        fprintf(stderr, "Failed to set redirect option [%s]\n", errorBuffer);

        return false;
    }

    code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
    if (code != CURLE_OK)
    {
        fprintf(stderr, "Failed to set writer [%s]\n", errorBuffer);

        return false;
    }

    code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer);
    if (code != CURLE_OK)
    {
        fprintf(stderr, "Failed to set write data [%s]\n", errorBuffer);

        return false;
    }

    return true;
}

//
//  libxml: ������ ������������ ����
//

static void StartElement(void* voidContext,
    const xmlChar* name,
    const xmlChar** attributes)
{
    Context* context = (Context*)voidContext;

    if (COMPARE((char*)name, "TITLE"))
    {
        context->title = "";
        context->addTitle = true;
    }
    (void)attributes;
}

//
//  libxml: ������ ������������ ����
//

static void EndElement(void* voidContext,
    const xmlChar* name)
{
    Context* context = (Context*)voidContext;

    if (COMPARE((char*)name, "TITLE"))
        context->addTitle = false;
}

//
//  ������ ��������� ������
//

static void handleCharacters(Context* context,
    const xmlChar* chars,
    int length)
{
    if (context->addTitle)
        context->title.append((char*)chars, length);
}

//
//  libxml: ������ �������� PCDATA
//

static void Characters(void* voidContext,
    const xmlChar* chars,
    int length)
{
    Context* context = (Context*)voidContext;

    handleCharacters(context, chars, length);
}

//
//  libxml ������ �������� CDATA
//

static void cdata(void* voidContext,
    const xmlChar* chars,
    int length)
{
    Context* context = (Context*)voidContext;

    handleCharacters(context, chars, length);
}

//
//  libxml: ��������� ������� SAX
//

static htmlSAXHandler saxHandler =
{
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  StartElement,
  EndElement,
  NULL,
  Characters,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  cdata,
  NULL
};

//
//  ���������� ����� HTML-�������� � ������� � ���������
//

static void parseHtml(const std::string& html,
    std::string& title)
{
    htmlParserCtxtPtr ctxt;
    Context context;

    ctxt = htmlCreatePushParserCtxt(&saxHandler, &context, "", 0, "",
        XML_CHAR_ENCODING_NONE);

    htmlParseChunk(ctxt, html.c_str(), html.size(), 0);
    htmlParseChunk(ctxt, "", 0, 1);

    htmlFreeParserCtxt(ctxt);

    title = context.title;
}

int main(int argc, char* argv[])
{
    CURL* conn = NULL;
    CURLcode code;
    std::string title;

    // ���������, ��� ����� ���� ��������

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);

        exit(EXIT_FAILURE);
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);

    // ���������������� ���������� CURL

    if (!init(conn, argv[1]))
    {
        fprintf(stderr, "Connection initializion failed\n");

        exit(EXIT_FAILURE);
    }

    // �������� �������� URL

    code = curl_easy_perform(conn);
    curl_easy_cleanup(conn);

    if (code != CURLE_OK)
    {
        fprintf(stderr, "Failed to get '%s' [%s]\n", argv[1], errorBuffer);

        exit(EXIT_FAILURE);
    }

    // ��������� ���������� ��������������� HTML-���� ��������

    parseHtml(buffer, title);

    // ������� ���������� ���������

    printf("Title: %s\n", title.c_str());

    return EXIT_SUCCESS;
}