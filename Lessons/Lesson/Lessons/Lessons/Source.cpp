#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>

using namespace std;



int past(int h, int m, int s) {
	return (h * 3600000 + m * 60000 + s * 1000);
}

std::string even_or_odd(int number)
{
	return ((number % 2) != 0) ? "Odd" : "Even";
}

int positive_sum(const std::vector<int> arr) {


	int summ = 0;
	for (int ia : arr)
	{
		if (ia > 0)
		{
			summ += ia;
		}
	}

	return summ;
}

int makeNegative(int num)
{
	return (num < 0) ? num : -num;
}

string sliceString(string str)
{
	
		char buf[30];
		size_t n = str.copy(buf, str.length() - 2, 1);
		buf[n] = '\0';	
	

	return buf;
}

std::string no_space(std::string x)
{
	int n = x.find(' ');
	while (n != -1)
	{
		x.replace(n, 1, "");
		n = x.find(' ');
	}

	return x;
}

int findSmallest(vector <int> list)
{
	int smallest = list.at(0);
	for (int i : list)
	{
		if (smallest > i)
		{
			smallest = i;
		}
	}
	return smallest;
}

int summation(int num) {

	int summ = 0;
	for (int i = 1; i <= num; i++)
	{
		summ += i;
	}
	return summ;
}

string bool_to_word(bool value)
{
	return value ? "Yes" : "No";
}

int count_sheep(vector<bool> arr)
{
	int count = 0;
	for (bool i : arr)
	{
		if (i)
		{
			count++;
		}
	}

	return count;
}

string reverseString(string str)
{
	int length = str.length() - 1;
	string strNew = "";
	for (size_t i = length; i > 0; i--)
	{
		strNew += str.at(i);
	}
	strNew += str.at(0);

	return strNew;
}

int centuryFromYear(int year)
{
	/*if ((year % 100) == 0)
	{
		return year / 100;
	}
	else
	{
		return  year / 100 + 1;
	}*/
	return ((year % 100) == 0) ? (year / 100) : (year / 100 + 1);
}

int basicOp(char op, int val1, int val2) {
	switch (op)
	{
	case '+':	return val1 + val2;
	case '-':	return val1 - val2;
	case '*':	return val1 * val2;
	case '/':	return val1 / val2;
	default:
		return 0;
	}
}

bool isDivisible(int n, int x, int y) {
return (((n % x) == 0) && ((n % y) == 0)) ? true : false;
}

vector<int> digitize(unsigned long n)
{
	vector<int> reverse;
	string str = to_string(n);
	unsigned long length = str.length();

	for (unsigned long i = 0; i < length; i++)
	{
		reverse.push_back(n / (unsigned long)(pow(10, i)) % 10);
	}

	return reverse;
}

int square_sum(const std::vector<int>& numbers)
{
	int result = 0;
	for (int i : numbers)
	{
		result += pow(i, 2);
	}
	return result;
}

std::string abbrevName(std::string name)
{
	int secondWord = name.find(' ');
	pair<char, char> initiales(name[0], name[secondWord + 1]);

	if (initiales.first > 'a' && initiales.first < 'z')
	{
		initiales.first -= 32;
	}

	string newName = "";
	newName = initiales.first;
	newName += ".";
	newName += initiales.second;
	return newName;
}

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
	if (input.size() == 0)
	{
		return input;
	}

	int positiveDigitsCount = 0;
	int summNegativeDigits = 0;


	for (int i : input)
	{
		if (i > 0)
		{
			positiveDigitsCount++;
		}
		else
		{
			summNegativeDigits += i;
		}
	}

	input.clear();
	input.push_back(positiveDigitsCount);
	input.push_back(summNegativeDigits);

	return input;

}

std::vector<int> maps(const std::vector<int>& values) {

	vector<int> result;
	for (int i : values)
	{
		result.push_back(i * 2);
	}
	return result;
}

int sum(vector<int> numbers)
{
	if (numbers.size() == 0)
	{
		return 0;
	}

	int minDigit = numbers.at(0);
	int maxDigit = numbers.at(0);
	int sum = 0;


	for (int i : numbers)
	{
		if (i < minDigit)
		{
			minDigit = i;
		}
		if (i > maxDigit)
		{
			maxDigit = i;
		}

		sum += i;
	}

	sum -= minDigit + maxDigit;

	return sum;

}

std::vector<int> invert(std::vector<int> values)
{
	
	vector<int>::iterator it = values.end() - 1;
	for (it = values.end() - 1; it > values.begin(); it--)
	{
		*it = *it * -1;
	}

	*it = *it * -1;

	return values;
}

int string_to_number(const std::string& s) {
	return stoi(s);
}

int points(const array<string, 10 > & games) {

	

	return 0;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	int r;
	r = points(array<string, 10>{"1:0", "2:0", "3:0", "4:0", "2:1", "3:1", "4:1", "3:2", "4:2", "4:3"});

	

	return 0;

}