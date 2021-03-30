/*  Tim max trong dso N phan tu
    Su dung con tro */

#include <iostream>
using namespace std;

int searchMax(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

int main()
{
    int n;
    int *arr = new int;
    if (arr == NULL)
    {
        cout << "\nKhong du bo  nho!" << endl;
        exit(0);
    }

    cout << "Nhap so phan tu N = ";
    cin >> n;

    cout << "\nNhap cac phan tu cua day so: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\ta[" << i << "] = ";
        cin >> arr[i];
    }
    cout << "\n==> So lon nhat trong day so la " << searchMax(arr, n) << endl;

    system("pause");
    return 0;
}