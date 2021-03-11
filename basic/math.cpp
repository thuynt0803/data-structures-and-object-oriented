#include <iostream>
#include <math.h>
using namespace std;

int math(int x, int y, char tt)
{
    switch (tt)
    {
    case '+':
        cout << "Bieu thuc: " << x << " + " << y << " = " << x + y << endl;
        break;
    case '-':
        cout << "Bieu thuc: " << x << " - " << y << " = " << x - y << endl;
        break;
    case '*':
        cout << "Bieu thuc: " << x << " * " << y << " = " << x * y << endl;
        break;
    case '%':
        cout << "Bieu thuc: " << x << " % " << y << " = " << x % y << endl;
        break;
    default:
        cout << "Khong co phep toan " << tt << endl;
        break;
    }
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

int prime(int x, int y) // Check for prime numbers (so nguyen to)
{
    int i, check = 1;
    for (i = 2; i <= (int(sqrt(x))); i++)
    {
    }
}

int main()
{
    int a, b;
    char tt, ch;
    cout << "Nhap a = ";
    cin >> a;
    cout << "Nhap b = ";
    cin >> b;
    do
    {
        cout << "Phep toan thuc hien: ";
        cin >> tt;
        math(a, b, tt);
        cout << "Thuc hien bieu thuc tiep theo? (Y/N) - ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    prime(a, b);

    cout << "--> UCLN(a,b) = " << gcd(a, b) << endl;
    cout << "--> BCNN(a,b) = " << lcm(a, b) << endl;
    return 0;
}
