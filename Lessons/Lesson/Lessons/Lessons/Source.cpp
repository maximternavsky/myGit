#include <iostream>
#include <vector>


using namespace std;


//size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
	vector<char> vectorChars;
	vector<char> newVector;
	bool isRepeatSymbol = false;
	int countRepeatSymbols = 0;
	while (*in != '\0')
	{
		char temp = *in;
		if (*in > 'A' && *in < 'Z')
		{
			temp = *in + 'z' - 'Z';
		}

		
		vectorChars.push_back(temp);
		in++;
	}

	while (vectorChars.size() > 1)
	{
		newVector.clear();

		char symbol = vectorChars.back();

		vectorChars.pop_back();

		for (char i : vectorChars)
		{
			if (i == symbol)
			{
				isRepeatSymbol = true;
			}
			else
			{
				newVector.push_back(i);
			}
		}

		vectorChars = newVector;

		if (isRepeatSymbol)
		{
			isRepeatSymbol = false;
			countRepeatSymbols++;
		}
	}
	

	return countRepeatSymbols;
}


int main()
{
	setlocale(LC_ALL, "Rus");

	/*char a[] = "q\q\\qweeeeettyyui777//\\**--__><><";
	
	cout << duplicateCount(a);*/

	for (int i = 0; i < 255; i++)
	{
		cout << char(i) << endl;
	}

	return 0;

}