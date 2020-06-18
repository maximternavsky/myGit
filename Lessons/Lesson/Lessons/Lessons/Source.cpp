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

string sliceString(string str)
{
	
		char buf[30];
		size_t n = str.copy(buf, str.length() - 2, 1);
		buf[n] = '\0';	
	

	return buf;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << sliceString("country") << endl;

	return 0;

}