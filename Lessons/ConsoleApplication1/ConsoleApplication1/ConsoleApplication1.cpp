

#include <iostream>
#include <ostream>
#include <istream>
#include <conio.h>

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



int main()
{
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
}
