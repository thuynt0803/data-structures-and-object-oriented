/**
 * Nhap vao danh sach phan tu
 * 1. Xuat ds phan tu sau khi sx tang dan (ung dung cac thuan toan sap xep: sx chen, sx chon, sx noi bot, sx vun dong, sx tron)
 * 2. Tim kiem max, min trong danh sach duoc nhap
 **/

#include <iostream>
using namespace std;

void inputArr(int *a, int n)
{
    cout << "\n\tNhap cac phan tu cua day so: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\t\ta[" << i << "] = ";
        cin >> a[i];
    }
}

void outputArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\n";
}

//SX chon - danh sach tang dan
void selectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    outputArr(a, n);
}

//SX chen - danh sach tang dan
void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = a[i];
        while (temp < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    outputArr(a, n);
}

//SX noi bot - danh sach tang dan
void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
    outputArr(a, n);
}

// Tim max
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

// Tim min
int searchMin(int *a, int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    return min;
}

void menu(int *a, int n)
{
    inputArr(a, n);
    while (true)
    {
        system("cls");
        cout << "\n\n\t ============================ MENU ============================\n"
             << endl;
        cout << "\t\t1. Xuat day so ban dau." << endl;
        cout << "\t\t2. Xuat danh sach tang dan - SX chon (selection sort)." << endl;
        cout << "\t\t3. Xuat danh sach tang dan - SX chen (insertion sort)." << endl;
        cout << "\t\t4. Xuat danh sach tang dan - SX noi bot (bubble sort)." << endl;
        cout << "\t\t5. Tim MAX." << endl;
        cout << "\t\t6. Tim MIN." << endl;
        cout << "\t\t0. Thoat." << endl;
        cout << "\n\t ============================= END =============================" << endl;

        int select;
        cout << "\n\tNhap lua chon cua ban: ";
        cin >> select;

        if (select < 0 || select > 6)
        {
            cout << "\n\tNOTE: Lua chon khong hop le, vui long nhap lai!\n\n";
            system("pause");
        }
        else if (select == 1)
        {
            cout << "\n\tDay so ban dau la: ";
            outputArr(a, n);
            system("pause");
        }
        else if (select == 2)
        {
            cout << "\n\tDanh sach sau khi sap xep tang dan la: ";
            selectionSort(a, n);
            system("pause");
        }
        else if (select == 3)
        {
            cout << "\n\tDanh sach sau khi sap xep tang dan la: ";
            insertionSort(a, n);
            system("pause");
        }
        else if (select == 4)
        {
            cout << "\n\tDanh sach sau khi sap xep tang dan la: ";
            bubbleSort(a, n);
            system("pause");
        }
        else if (select == 5)
        {
            cout << "\n\tGia tri lon nhat trong day so: MAX(arr) = " << searchMax(a, n) << endl;
            system("pause");
        }
        else if (select == 6)
        {
            cout << "\n\tGia tri nho nhat trong day so: MIN(arr) = " << searchMin(a, n) << endl;
            system("pause");
        }
        else
        {
            cout << "\n\tHOAN THANH CHUONG TRINH !!!\n\n";
            break;
        }
    }
}

int main()
{
    int n;
    int *arr = new int;
    if (arr == NULL)
    {
        cout << "\nKhong du bo nho!" << endl;
        exit(0);
    }
    cout << "\n\tNhap so phan tu: N = ";
    cin >> n;

    menu(arr, n);

    system("pause");
    return 0;
}