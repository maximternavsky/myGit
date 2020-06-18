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

int main()
{
	setlocale(LC_ALL, "Rus");



	return 0;

}