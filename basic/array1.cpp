#include <iostream>
using namespace std;

#define N 50

void inputArr(int a[], int n)
{
    cout << "Nhap day so: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\ta[" << i << "] = ";
        cin >> a[i];
    }
}

int outputArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "  " << a[i];
    }
}

int increaseSortUp(int a[], int n)
{
    int tg;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Hoan vi 2 so a[i] va a[j]
            if (a[i] > a[j])
            {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
    cout << "\nDay so sau khi sap xep tang dan:" << endl;
    outputArr(a, n);
}

int decreaseSortUp(int a[], int n)
{
    int tg;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Hoan vi 2 so a[i] va a[j]
            if (a[i] < a[j])
            {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
    cout << "\nDay so sau khi sap xep giam dan:" << endl;
    outputArr(a, n);
}

int main()
{
    int n, a[N];
    do
    {
        cout << "Nhap so phan tu: n = ";
        cin >> n;
        if (n > N)
        {
            cout << "So phan tu nhap qua gioi han. Vui long nhap lai!" << endl;
        }
        cout << endl;
    } while (n >= N);

    inputArr(a, n);
    increaseSortUp(a, n);
    decreaseSortUp(a, n);
    return 0;
}