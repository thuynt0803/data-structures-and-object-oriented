/*
    Yêu cầu: Nhập danh sách nhân sự với thông tin của nhân sự gồm: họ tên, ngày sinh, quê quán, ngày vào cơ quan, mức lương.
    Trong đó:   - Họ tên là một cấu trúc có 3 thành phần: họ, tên đệm, tên
                - Ngày sinh & ngày vào có quan cùng một kiểu cấu trúc gồm: ngày, tháng, năm
                - Tìm kiếm và in ra nhân viên có mức lương thấp nhất và cao nhất
*/

#include <iostream>
#include <cstdio>
using namespace std;
#define N 100
struct name
{
    char ho[15];
    char tendem[15];
    char ten[15];
};

struct date
{
    int day;
    int month;
    int year;
};

struct employee
{
    name hoten;
    date ngaysinh;
    char quequan[50];
    date ngayvaolam;
    int luong;
};

void inputListEmployee(employee *ptr, int n)
{
}

int main()
{
    int n;
    employee listEmployee[N];
    employee *ptr = listEmployee;

    do
    {
        cout << "Nhap so nhan su: ";
        cin >> n;
        if (n > N)
        {
            cout << "So luong nhan vu vuot qua gioi han. Vui long nhap lai!" << endl;
        }
        cout << endl;
    } while (n > N);
}
