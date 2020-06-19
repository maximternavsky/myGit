#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//
//
//int past(int h, int m, int s) {
//	return (h * 3600000 + m * 60000 + s * 1000);
//}
//
//std::string even_or_odd(int number)
//{
//	return ((number % 2) != 0) ? "Odd" : "Even";
//}
//
//int positive_sum(const std::vector<int> arr) {
//
//
//	int summ = 0;
//	for (int ia : arr)
//	{
//		if (ia > 0)
//		{
//			summ += ia;
//		}
//	}
//
//	return summ;
//}
//
//int makeNegative(int num)
//{
//	return (num < 0) ? num : -num;
//}
//
//string sliceString(string str)
//{
//	
//		char buf[30];
//		size_t n = str.copy(buf, str.length() - 2, 1);
//		buf[n] = '\0';	
//	
//
//	return buf;
//}
//
//std::string no_space(std::string x)
//{
//	int n = x.find(' ');
//	while (n != -1)
//	{
//		x.replace(n, 1, "");
//		n = x.find(' ');
//	}
//
//	return x;
//}
//
//int findSmallest(vector <int> list)
//{
//	int smallest = list.at(0);
//	for (int i : list)
//	{
//		if (smallest > i)
//		{
//			smallest = i;
//		}
//	}
//	return smallest;
//}
//
//int summation(int num) {
//
//	int summ = 0;
//	for (int i = 1; i <= num; i++)
//	{
//		summ += i;
//	}
//	return summ;
//}
//
//string bool_to_word(bool value)
//{
//	return value ? "Yes" : "No";
//}
//
//int count_sheep(vector<bool> arr)
//{
//	int count = 0;
//	for (bool i : arr)
//	{
//		if (i)
//		{
//			count++;
//		}
//	}
//
//	return count;
//}
//
//string reverseString(string str)
//{
//	int length = str.length() - 1;
//	string strNew = "";
//	for (size_t i = length; i > 0; i--)
//	{
//		strNew += str.at(i);
//	}
//	strNew += str.at(0);
//
//	return strNew;
//}
//
//int centuryFromYear(int year)
//{
//	/*if ((year % 100) == 0)
//	{
//		return year / 100;
//	}
//	else
//	{
//		return  year / 100 + 1;
//	}*/
//	return ((year % 100) == 0) ? (year / 100) : (year / 100 + 1);
//}
//
//int basicOp(char op, int val1, int val2) {
//	switch (op)
//	{
//	case '+':	return val1 + val2;
//	case '-':	return val1 - val2;
//	case '*':	return val1 * val2;
//	case '/':	return val1 / val2;
//	default:
//		return 0;
//	}
//}
//
//bool isDivisible(int n, int x, int y) {
//	return (((n % x) == 0) && ((n % y) == 0)) ? true : false;
//}

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

int main()
{
	setlocale(LC_ALL, "Rus");
	vector<int> a = digitize(45762893920);
	//cout << isDivisible(3, 3, 4) << endl;

	return 0;

}