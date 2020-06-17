#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


#include <string>
using namespace std;

string getFruit(int num);

string SubtractSum(int n)
{
	int summ;
	string str;
	int length;

	while (n > 100)
	{
		summ = 0;
		str = to_string(n);
		length = str.length() - 1;
		
		for (int i = 0, j = length; i < length + 1; i++, j--)
		{
			summ += n / (int)((i == length) ? 1 : pow(10, j)) % 10;
		}

		n = n - summ;

	}

	return getFruit(n);
}

string getFruit(int num)
{
	string str[] = {
		"",
		"kiwi",
		"pear",
		"kiwi",
		"banana",
		"melon",
		"banana",
		"melon",
		"pineapple",
		"apple",
		"pineapple",
		"cucumber",
		"pineapple",
		"cucumber",
		"orange",
		"grape",
		"orange",
		"grape",
		"apple",
		"grape",
		"cherry",
		"pear",
		"cherry",
		"pear",
		"kiwi",
		"banana",
		"kiwi",
		"apple",
		"melon",
		"banana",
		"melon",
		"pineapple",
		"melon",
		"pineapple",
		"cucumber",
		"orange",
		"apple",
		"orange",
		"grape",
		"orange",
		"grape",
		"cherry",
		"pear",
		"cherry",
		"pear",
		"apple",
		"pear",
		"kiwi",
		"banana",
		"kiwi",
		"banana",
		"melon",
		"pineapple",
		"melon",
		"apple",
		"cucumber",
		"pineapple",
		"cucumber",
		"orange",
		"cucumber",
		"orange",
		"grape",
		"cherry",
		"apple",
		"cherry",
		"pear",
		"cherry",
		"pear",
		"kiwi",
		"pear",
		"kiwi",
		"banana",
		"apple",
		"banana",
		"melon",
		"pineapple",
		"melon",
		"pineapple",
		"cucumber",
		"pineapple",
		"cucumber",
		"apple",
		"grape",
		"orange",
		"grape",
		"cherry",
		"grape",
		"cherry",
		"pear",
		"cherry",
		"apple",
		"kiwi",
		"banana",
		"kiwi",
		"banana",
		"melon",
		"banana",
		"melon",
		"pineapple",
		"apple",
		"pineapple"};

		return str[num];
}


int main()
{
	setlocale(LC_ALL, "Rus");


	
	cout << SubtractSum(10) << endl;
	cout << SubtractSum(1086) << endl;
	cout << SubtractSum(143450) << endl;
	cout << SubtractSum(1760) << endl;
	cout << SubtractSum(8690) << endl;
	cout << SubtractSum(789) << endl;
	cout << SubtractSum(7432) << endl;
	cout << SubtractSum(452) << endl;
	cout << SubtractSum(567567) << endl;
	cout << SubtractSum(355) << endl;
	cout << SubtractSum(234) << endl;
	cout << SubtractSum(754634) << endl;
	cout << SubtractSum(1323) << endl;
	cout << SubtractSum(345) << endl;



	

	return 0;

}