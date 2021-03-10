#include <iostream>
using namespace std;

int myTong(int x, int y)
{
    return x + y;
}

int myHieu(int x, int y)
{
    return x - y;
}

int myTich(int x, int y)
{
    return x * y;
}

int mySodu(int x, int y)
{
    return x / y;
}

int gcd(int x, int y) // GCD – Greatest Common Divisor (UCLN)
{
    // if x = 0 => UCLN(x,y) = y
    // if y = 0 => UCLN(x,y) = x
    if (x == 0 || y == 0)
    {
        return x + y;
    }

    while (x * y != 0)
    {
        if (x > y)
        {
            x -= y;
        }
        else
        {
            y -= x;
        }
    }
    return x;
}

int lcm(int x, int y) // LCM - lowest common multiple (BCNN)
{
    return x * y / gcd(x, y);
}

int main()
{
    int a, b;
    cout << "Nhap a = ";
    cin >> a;
    cout << "Nhap b = ";
    cin >> b;
    cout << "--> Tong a + b = " << myTong(a, b) << endl;
    cout << "--> Hieu a - b = " << myHieu(a, b) << endl;
    cout << "--> Tich a * b = " << myTich(a, b) << endl;
    cout << "--> Thuong a / b = " << mySodu(a, b) << endl;
    cout << "--> UCLN(a,b) = " << gcd(a, b) << endl;
    cout << "--> BCNN(a,b) = " << lcm(a, b) << endl;
    return 0;
}
