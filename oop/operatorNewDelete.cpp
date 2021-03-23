/*
    * Cấp phát động bộ nhớ
    * Yêu cầu: Tạo 1 mảng động, khởi tạo mảng với các giá trị ngẫn nhiên và sắp xếp chúng.
*/

#include <iostream>
using namespace std;

int x = 10;
int main()
{
    //========== Tham chiếu đến biến toàn cục, sử dụng ::<tên biến> ==========
    int x = 5;
    cout << "x = " << x << endl;   // x =5
    cout << "x = " << ::x << endl; // x = 10

    //========== Tham chiếu tới 1 biến bằng ký tự '&' ==========
    int n;
    int &p = n; //Tham chiếu p đến vùng nhớ n
    n = 3;
    cout << p; //cho giá trị là 3 --> sử dụng p và n như nhau

    //========== Cấp phát bộ nhớ động ==========
    int m, *ptr;
    cout << "Nhap m = ";
    cin >> m;
    ptr = new int[m]; // Cấp phát 50 ô nhớ 2 byte và gán địa chỉ đầu của vùng nhớ cho ptr
    for (int i = 0; i < m; i++)
    {
        cout << "Phan tu dau " << i << ":" << ptr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cout << "Phan tu thu " << i << " = " << ptr[i] << endl;
    }

    delete[] ptr;

    return 0;
}