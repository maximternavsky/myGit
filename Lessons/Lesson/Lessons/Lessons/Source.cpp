#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <ctime>

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

//int square_sum(const std::vector<int>& numbers)
//{
//	int result = 0;
//	for (int i : numbers)
//	{
//		result += pow(i, 2);
//	}
//	return result;
//}

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

std::vector<int> MonkeyCount(int n) {

	vector<int> result;
	for (int i = 1; i <= n; i++)
	{
		result.push_back(i);
	}

	return result;
}

string bonus_time(int salary, bool bonus)
{
	string f = "$" + to_string(100000 * 10);
	return bonus ? "\$" + to_string(salary * 10) : "\$" + salary;
}


double calcAverage(const std::vector<int>& values) {

	double sum = 0;

	for (int i : values)
	{
		sum += i;
	}

	return sum / values.size();
}

std::vector<int> reverseSeq(int n) {

	std::vector<int> result;
	for (int i = n; i > 0; i--)
	{
		result.push_back(i);
	}

	return result;
}

std::string rps(const std::string& p1, const std::string& p2)
{

	if (p1 == p2) return "Draw!";
	if (p1 == "rock" && p2 == "scissors") return "Player 1 won!";
	if (p1 == "rock" && p2 == "paper") return "Player 2 won!";
	if (p1 == "scissors" && p2 == "rock") return "Player 2 won!";
	if (p1 == "scissors" && p2 == "paper") return "Player 1 won!";
	if (p1 == "paper" && p2 == "rock") return "Player 1 won!";
	if (p1 == "paper" && p2 == "scissors") return "Player 2 won!";
		
}

std::string fakeBin(std::string str) {
	std::string result = "";
	const int CONSTCHAR = 48;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i]) >= 5 + CONSTCHAR)
		{
			result.push_back('1');
		}
		else
		{
			result.push_back('0');
		}
	}

	return result;
}

std::string DNAtoRNA(std::string dna) {
	int count = dna.find('T');
	
	while (count != -1)
	{
		dna.replace(count, 1, "U");
		count = dna.find('T');
	}

	return dna;
}

int min(vector<int> list) {

	if (list.size() == 0) return 0;

	int minDigit = list.at(0);

	for (int i : list)
	{
		if (i < minDigit) minDigit = i;
	}
	return minDigit;
}

int max(vector<int> list) {

	if (list.size() == 0) return 0;

	int maxDigit = list.at(0);

	for (int i : list)
	{
		if (i > maxDigit) maxDigit = i;
	}
	return maxDigit;
}

#include <vector>
int grow(std::vector<int> nums) {
	int mult = 1;

	for (int i : nums)
	{
		mult *= i;
	}

	return mult;
}

std::string countSheep(int number) {

	std::string sheep = " sheep...";
	std::string result = "";
	if (number == 0) return 0;
	for (int i = 0; i < number; i++)
	{
		result += to_string(i + 1);
		result += sheep;
	}

	return result;
}

int arrayPlusArray(std::vector<int> a, std::vector<int> b) {

	int sum = 0;

	for (int i : a)
	{
		sum += i;
	}
	for (int i : b)
	{
		sum += i;
	}

	return sum; 
}

string to_alternating_case(const string& str)
{
	string result = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			result.push_back(str[i] + 32);
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
		{
			result.push_back(str[i] - 32);
		}
		else
		{
			result.push_back(str[i]);
		}

	}

	return result;
}

bool betterThanAverage(std::vector<int> classPoints, int yourPoints) {

	double average = 0;
	for (int i : classPoints)
	{
		average += i;
	}

	if (average / classPoints.size() > yourPoints)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int simpleMultiplication(int a) {
	return (a % 2 != 0) ? a * 9 : a * 8;
}

bool feast(std::string beast, std::string dish) {
	
	if (beast.at(0) == dish.at(0) && beast.at(beast.length() - 1) == dish.at(dish.length() - 1))
	{
		return true;
	}

	return false;
}

int sum1(std::vector<int> nums) {
	if (nums.size() == 0) return 0;
	
	int sum = 0;

	for (int i : nums)
	{
		sum += i;
	}

	return sum;
}

int odd_count(int n) {

	int count = -1;

	if (n % 2 == 0)
	{
		n--;
		count++;
	}


	for (int i = n; i > 0; i -= 2)
	{
		count++;
	}

	return count;
}

std::string correct(std::string str) {
	for (char &i : str)
	{
		switch (i)
		{
		case '5': i = 'S'; break;
		case '0': i = 'O'; break;
		case '1': i = 'I'; break;
		default: break;
		}
	}

	return str;
}

bool zero_fuel(uint32_t distance_to_pump, uint32_t mpg, uint32_t fuel_left)
{
	return (fuel_left * mpg) >= distance_to_pump ? true : false;
}

bool hero(int bullets, int dragons) {
	return dragons * 2 <= bullets;
}

std::string bmi(double w, double h)
{

	//throw std::logic_error("Method or operation is not implemented");

	float bmi = w / pow(h, 2);

	if (bmi <= 18.5) return "Underweight";

	if (bmi <= 25.0) return "Normal";

	if (bmi <= 30.0) return "Overweight";

	if (bmi > 30) return "Obese";
}

std::string makeUpperCase(const std::string& input_str)
{
	string result = "";
	for (char i : input_str)
	{
		if (i >= 'a' && i <= 'z') 
		{
			result.push_back(i - 32);
		}
		else
		{
			result.push_back(i);
		}
	}

	return result;
}

int get_average(std::vector <int> marks)
{
	int sum = 0;

	for (int i : marks)
	{
		sum += i;
	}

	int average = sum / marks.size();

	return average;
}

std::string removeExclamationMarks(std::string str) {
	int exclamat = str.find('!');
	while (exclamat != -1)
	{
		str.erase(exclamat, 1);
		exclamat = str.find('!');
	}

	return str;
}

std::string how_much_i_love_you(int nb_petals) {

	if (nb_petals > 6) nb_petals %= 6; nb_petals++;

	switch (nb_petals)
	{
	case(1): return "I love you";
	case(2): return "a little";
	case(3): return "a lot";
	case(4): return "passionately";
	case(5): return "madly";
	case(0): return "not at all";
	default: return "";
	}
}

std::string boolean_to_string(bool b) {
	return b ? "true" : "false";
}

std::vector<int> divisible_by(std::vector<int> numbers, int divisor)
{
	vector<int> result;

	for (int i : numbers)
	{
		if (i % divisor == 0) result.push_back(i);
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	

	how_much_i_love_you(283);
	

	return 0;

}