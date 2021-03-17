#include <iostream>
using namespace std;
#define N 50
int numbers[N];

int inputArr(int *p, int n)
{
    cout << "Nhap vao day so numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\tnumbers[" << i << "] = ";
        cin >> *(p + i);
    }
}

int outputArr(int *p, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "  " << *(p + i);
    }
    cout << endl;
}

int sortIncrease(int *p, int n)
{
    int tg;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Hoan vi 2 so a[i] va a[j]
            if (*(p + i) > *(p + j))
            {
                tg = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = tg;
            }
        }
    }
}

bool checkX(int *p, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) == x)
        {
            return 1;
        }
    }
    return 0;
}

int countX(int *p, int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkX(p, n, x) == 1)
        {
            count++;
        }
    }
    cout << "\t- Phan tu 'x' xuat hien " << count << " lan trong day so." << endl;
}

int locationX(int *p, int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        if (checkX(p, n, x) == 1)
        {
            cout << "\t" << i + 1;
        }
    }
}

int firstX(int *p, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (*(p + i) == x)
            return i;
}

int lastX(int *p, int n, int x)
{
    int location;
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) == x)
        {
            location = i;
        }
    }
    return location;
}

int main()
{
    int *p, x, n;
    p = numbers;
    do
    {
        cout << "Nhap so phan tu: n = ";
        cin >> n;
        if (n > N)
        {
            cout << "NOTE: So phan tu nhap qua gioi han (50). Vui long nhap lai!" << endl;
        }
    } while (n > N);

    inputArr(p, n);
    // outputArr(p, n);
    cout << "Phan tu can tim: x = ";
    cin >> x;

    countX(p, n, x);
    cout << "\t- Cac vi tri xuat hien 'x' trong day so la: " << locationX(p, n, x) << endl;
    cout << "\t- Vi tri xuat hien 'x' dau tien trong day ban dau la numbers[" << firstX(p, n, x) << "]." << endl;
    cout << "\t- Vi tri xuat hien 'x' cuoi cung trong day ban dau la numbers[" << lastX(p, n, x) << "]." << endl;

    sortIncrease(p, n);
    cout << "Day so sau khi sap xep tang dan:";
    outputArr(p, n);

    return 0;
}
