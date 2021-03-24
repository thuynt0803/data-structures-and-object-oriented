#include <iostream>
#include <time.h>   // thu vien ho tro tao so ngau nhien khac nhau sau moi lan random
#include <stdlib.h> // thu vien chua ham random
using namespace std;

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int *p;
    p = new int[n];
    /*
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << " = ";
        cin >> *(p + i);
    }
    */

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        *(p + i) = rand() % 99 + 1;
    }

    cout << "Day so random: ";
    for (int i = 0; i < n; i++)
    {
        cout << *(p + i) << "\t";
    }

    //Sap xep day so tang dan
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(p + i) > *(p + j))
            {
                swap(*(p + i), *(p + j)); // ham doi cho
            }
        }
    }

    cout << "\nDay so duoc nhap: ";
    for (int i = 0; i < n; i++)
    {
        cout << *(p + i) << "\t";
    }

    return 0;
}
