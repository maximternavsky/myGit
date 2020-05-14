

#include <iostream>
#include <ostream>
#include <istream>


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


int main()
{
    Int i(5);
    cout << i;
}
