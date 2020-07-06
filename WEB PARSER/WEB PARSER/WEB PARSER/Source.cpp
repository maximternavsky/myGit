
#define CURL_STATICLIB
#include <curl/curl.h>
#include <iostream>

int main()
{
    CURL* curl_handle = curl_easy_init();
    if (curl_handle)
    {
        setlocale(LC_ALL, "RUS");
        // ������  url �����
        curl_easy_setopt(curl_handle, CURLOPT_URL, "https://bagk-med.ru/schedule/record_wizard.php?STEP=service&SHOW=employee&EMPLOYEE=64");
        // ��������� ������
        CURLcode res = curl_easy_perform(curl_handle);
        // ��������� ���������� curl
        curl_easy_cleanup(curl_handle);
    }

    getchar();
    return 0;
}