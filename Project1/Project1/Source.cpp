#include <iostream>

using namespace std;

class Point;

class Human
{
public:
	void SetPoint(Point &point);
};

class Point
{
public:

	bool operator == (const Point &point)
	{
		return this->x == point.x && this->y == point.y;
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void Print()
	{
		cout << this->x << "\t" << this->y << endl;
	}
private:
	int x, y;
	friend void Human::SetPoint(Point &point);
};

void Human::SetPoint(Point& point)
{
	point.x = 15;
	point.y = 112;
}

class MyString
{
public:
	MyString()
	{
		this->str = nullptr;
	}

	MyString(const char* str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';

	}

	~MyString()
	{
		delete[] str;
	}

	bool operator ==(const MyString& string)
	{
		if (strlen(this->str) == strlen(string.str))
		{
			for (int i = 0; i < strlen(this->str); i++)
			{
				if (this->str[i] != string.str[i])
				{
					return false;
				}
			}
		}
		else {
			return false;
		}
		return true;
	}
	bool operator !=(const MyString& string)
	{
		return !(this->operator==(string));
	}

	MyString operator +(const MyString& string)
	{
		int len1 = strlen(this->str);
		int len2 = strlen(string.str);

		MyString s;
		s.str = new char[len1 + len2 + 1];

		int i = 0;
		for (; i < len1; i++)
		{
			s.str[i] = this->str[i];
		}
		for (int j = 0; j < len2; j++, i++)
		{
			s.str[i] = string.str[j];
		}
		s.str[len1 + len2] = '\0';

		return s;
	}

	MyString& operator =(const MyString& string)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		int length = strlen(string.str);
		this->str = new char[length+1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = string.str[i];
		}
		this->str[length] = '\0';

		return *this;
	}

	


	char& operator [](int r)
	{
		return this->str[r];
	}

	MyString& Change (int p, char s)
	{
		this->str[p] = s;
		return *this;
	}

	void Print() 
	{
		cout << str << endl;
	}
	

	MyString(const MyString& string)
	{
		int length = strlen(string.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = string.str[i];
		}
		this->str[length] = '\0';
	}

	MyString(MyString&& string)
	{
		this->str = string.str;
		string.str = nullptr;
	}

	int Length()
	{
		return strlen(this->str);
	}
private:
	char* str;
};

int main()
{
	MyString a1("Hello");
	MyString a2("Maxim");
	MyString a3;
	a3 = a2 + a1;


	return 0;
}

