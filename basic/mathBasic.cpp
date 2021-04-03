/*
    Thư viện toán học: cmath    
    Các hàm toán  học:
        - hàm mũ: pow(x,n)
        - hàm tính căn bậc 2 của 1 số: sqrt(x)
        - hàm tính trị tuyệt đối: abs(x)
        - hàm tính e mũ x: exp(x)
        - hàm lượng giác: sin(x); cos(x); tan(x); 1/tan(x);
        - hàm tính logarit: log(x); ln(xl = og10(x);
*/

#include <iostream>
#include <math.h>
using namespace std;

int math(int x, int y, char tt)
{
    switch (tt)
    {
    case '+':
        cout << "\t==> Result: " << x << " + " << y << " = " << x + y << endl;
        break;
    case '-':
        cout << "\t==> Result: " << x << " - " << y << " = " << x - y << endl;
        break;
    case '*':
        cout << "\t==> Result: " << x << " * " << y << " = " << x * y << endl;
        break;
    case '%':
        cout << "\t==> Result: " << x << " % " << y << " = " << x % y << endl;
        break;
    default:
        cout << "\t==> Operator " << tt << " is not valid " << endl;
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
    if (x < 2)
    {
        cout << "\t==> " << x << " is not a prime number." << endl;
        return 0;
    }

    int i, countX = 0;
    for (i = 2; i <= (int(sqrt(x))); i++)
    {
        if (x % i == 0)
        {
            countX++;
        }
    }

    if (countX == 0)
    {
        cout << "\t==> " << x << " is a prime number." << endl;
    }
    else
        cout << "\t==> " << x << " is not a prime number." << endl;

    if (y < 2)
    {
        cout << "\t==> " << y << " is not a prime number." << endl;
        return 0;
    }

    int j, countY = 0;
    for (j = 2; j <= (int(sqrt(y))); j++)
    {
        if (y % j == 0)
        {
            countY++;
        }
    }

    if (countY == 0)
    {
        cout << "\t==> " << y << " is a prime number." << endl;
    }
    else
        cout << "\t==> " << y << " is not a prime number." << endl;
}

int main()
{
    int a, b;
    char tt, ch;
    cout << "Enter a = ";
    cin >> a;
    cout << "Enter b = ";
    cin >> b;

    cout << "Math expression:" << endl;
    do
    {
        cout << "Operator expression: "; //Bieu thuc toan tu
        cin >> tt;
        math(a, b, tt);
        cout << "Work with another operator? (Y/N) - ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    cout << "Check for prime numbers:" << endl;
    prime(a, b);

    cout << "Check UCLN, BCNN of 2 numbers:" << endl;
    cout << "\t==> UCLN(a,b) = " << gcd(a, b) << endl;
    cout << "\t==> BCNN(a,b) = " << lcm(a, b) << endl;

    return 0;
}
