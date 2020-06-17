#include <iostream>
#include <vector>
std::vector<int> countBy(int x, int n) {

	int xBefore = x;
	int mult = x * n;
	std::vector<int> array;

	array.push_back(x);
	while (x < mult)
	{
		array.push_back(x + xBefore);
		x += xBefore;
	}


	return array;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	countBy(100, 5);

	return 0;

}