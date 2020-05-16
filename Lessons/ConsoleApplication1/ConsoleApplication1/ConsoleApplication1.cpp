
//стр 258

#include <iostream>
#include <ostream>
#include <istream>
#include <conio.h>
#include <string>

//#define TOLBOOTH
//#define TIME
//#define EMPLOYEE
#define DATE

#define LEFT 75
#define RIGHT 77
#define ESC 27


using namespace std;

class Int
{
    int x;
public:
    Int()  
    {
        x = 0;
    }

    Int(int a) : x(a)
    {}

    void set(int a)
    {
        x = a;
    }

    Int operator+(Int& a) const
    {
        Int b(x + a.x);

        return b;
    }

    void setInt(int a) 
    {
        x=a;
    }

    int getX()
    {
        return x;
    }

    

};

ostream& operator << (ostream& os, Int a)
{
    os << a.getX();
    return os;
}

class tolBooth
{
    unsigned int countCar;
    double cash;
public:
    tolBooth() : countCar(0), cash(0)
    {}

    void payingCar()
    {
        countCar++;
        cash += 0.5;
    }

    void nopayCar()
    {
        countCar++;
    }

    void display() const
    {
        cout << "Количество машин - " << countCar << endl;
        cout << "Сумма выручки - " << cash << endl;
    }
};

class time
{
public:
    int hour, minute, second;

    friend ostream;

    time() : hour(0), minute(0), second(0)
    {}

    time(int h, int m, int s) : hour(h),minute(m),second(s)
    {
    }

    time& operator + (time& other) const
    {
        time newTime(hour + other.hour,minute + other.minute, second + other.second);
        return newTime;
    }

};

ostream& operator << (ostream& os, time t) 
{
    os << t.hour << ":" << t.minute << ":" << t.second << endl;
    return os;
}

class employee
{
    int number;
    float salary;

public:

    employee()
    {

    }

    employee(int number, float salary) : number(number), salary(salary)
    {

    }

    void setData()
    {
        int num;
        float sal;
        cout << "Enter number" << endl;
        cin >> num;
        cout << "Enter salary" << endl;
        cin >> sal;
        this->number = num;
        this->salary = sal;
    }

    int getNumber()
    {
        return number;
    }

    int getSalary()
    {
        return salary;
    }

};

ostream& operator<<(ostream& os, employee& obj)
{
    os << "number: " << obj.getNumber() << " salary: " << obj.getSalary() << endl;
    return os;
}

class Date
{
    int month, day, year;

public:
    void getdate(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void showdata()
    {
        string str = to_string(day) + "." + to_string(month) + "." + to_string(year);
        cout << str << endl;
    }
};


int main()
{
#ifdef TOLBOOTH

    tolBooth kassa;
    setlocale(LC_ALL, "ru");

    while (true)
    {
        if (_getch() == LEFT)
        {
            kassa.payingCar();
        }
        else if (_getch() == RIGHT)
        {
            kassa.nopayCar();
        }
        else if (_getch() == ESC)
        {
            kassa.display();
        }
        
    }
#endif

#ifdef TIME
    time t1(5, 5, 5);
    time t2(4, 4, 4);
    time t3;
    t3 = t1 + t2;
    cout << t3;
#endif

#ifdef EMPLOYEE
    employee p1, p2, p3;
    p1.setData();
    p2.setData();
    p3.setData();

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
#endif 

#ifdef DATE
    Date d;
    d.getdate(15, 02, 2020);
    d.showdata();
#endif 


    return 0;
}
