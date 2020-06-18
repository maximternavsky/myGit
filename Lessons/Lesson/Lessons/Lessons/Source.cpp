#include <iostream>
#include <vector>

using namespace std;

unsigned short int expressionsMatter(unsigned short int a, unsigned short int b, unsigned short int c)
{
	vector<unsigned short int> results;

	unsigned short int bigNumber = 0;

	results.push_back(a * b * c);
	results.push_back(a + b + c);
	results.push_back((a + b) * c);
	results.push_back(a * b + c);
	for (unsigned short int i : results)
	{
		if (i > bigNumber)
		{
			bigNumber = i;
		}
	}
	return bigNumber;
}

int main()
{
	setlocale(LC_ALL, "Rus");



	return 0;

}