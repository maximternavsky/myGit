
//стр 258

#include <iostream>
#include <ostream>
#include <istream>
#include <conio.h>
#include <string>

//#define TOLBOOTH
//#define TIME
//#define EMPLOYEE
//#define DATE
//#define ANGLE
#define MYCLASS

#define LEFT 75
#define RIGHT 77
#define ESC 27


using namespace std;

class Date;

enum napr
{
    North,
    West,
    East,
    South
};

enum etype
{
    Лаборант,
    Секретарь,
    Менеджер
};

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

class Date
{
    int month, day, year;

public:
    Date();
    void setdate(int day, int month, int year)
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

    string getdata()
    {
        string str = to_string(day) + "." + to_string(month) + "." + to_string(year);
        return str;
    }
};

Date::Date()
{

}

class employee
{
    friend Date;
    int number;
    float salary;
    Date date;
    etype dolznost;

public:

    employee() : number(0), salary(0), date(), dolznost()
    {

    }

    employee(int number, float salary, Date date, etype dolznost) : number(number), salary(salary), date(date), dolznost(dolznost)
    {

    }

    void setData()
    {
        int num;
        float sal;
        int dol;
        Date dat;
        cout << "Enter number" << endl;
        cin >> num;
        cout << "Enter salary" << endl;
        cin >> sal;
        dat.setdate(15,02,2020);
        cout << "Enter etype" << endl;
        cin >> dol;
        this->number = num;
        this->salary = sal;
        this->date = dat;
        this->dolznost = etype(dol);
    }

    int getNumber()
    {
        return number;
    }

    int getSalary()
    {
        return salary;
    }

    string getDate()
    {
        return date.getdata();
    }

    etype getetype()
    {
        return dolznost;
    }

};

ostream& operator<<(ostream& os, employee& obj)
{
    os << "number: " << obj.getNumber() << " salary: " << obj.getSalary() << " date: " << obj.getDate() << " etype: " << obj.getetype() << endl;
    return os;
}

class Angle
{
    int grad;
    float minute;
    char curs;
public:
    Angle(int grad, float minute, char curs) : grad(grad), minute(minute), curs(curs)
    {}

    void setPoint(int grad, float minute, char curs) 
    {
        this->grad = grad;
        this->minute = minute;
        this->curs = curs;
    }

    void setPoint()
    {
        cout << "grag: ";
        cin >> grad;
        cout << " minute: ";
        cin >> minute;
        cout << " curs: ";
        cin >> curs;
    }

    int getGrad()
    {
        return grad;
    }

    float getMinute()
    {
        return minute;
    }

    char getCurs()
    {
        return curs;
    }
};

ostream& operator<<(ostream& os, Angle& other)
{
    os << other.getGrad() << '\xF8' << other.getMinute() << '\'' << ' ' << other.getCurs() << endl;
    return os;
}

class myClass
{
    static int numb;
public:
    myClass()
    {
        numb++;
    }

    void showNumb()
    {
        cout << "My number: " << numb << endl;
    }
};

int myClass::numb = 0;

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
    /*p2.setData();
    p3.setData();*/

    cout << p1 << endl;
   /* cout << p2 << endl;
    cout << p3 << endl;*/
#endif 

#ifdef DATE
    Date d;
    d.setdate(15, 02, 2020);
    d.showdata();
#endif 

#ifdef ANGLE
    Angle a(170, 12.5, 'W');
    cout << a;

    while (true)
    {
        a.setPoint();
        cout << a;
    }
#endif

#ifdef MYCLASS
    myClass a;
    myClass b;
    myClass c;

    b.showNumb();
#endif

    return 0;
}
