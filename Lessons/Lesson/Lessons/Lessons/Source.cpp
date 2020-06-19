#include <iostream>
#include <vector>

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

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << no_space("8 j 8   mBliB8g  imjB8B8  jl  B") << endl;

	return 0;

}