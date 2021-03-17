/*
    Yêu cầu: Nhập danh sách nhân sự với thông tin của nhân sự gồm: họ tên, ngày sinh, quê quán, ngày vào cơ quan, mức lương.
    Trong đó:   - Họ tên là một cấu trúc có 3 thành phần: họ, tên đệm, tên
                - Ngày sinh & ngày vào cơ quan cùng một kiểu cấu trúc gồm: ngày, tháng, năm
                - Tìm kiếm và in ra nhân viên có mức lương thấp nhất và cao nhất
*/

#include <iostream>
#include <cstdio>
using namespace std;

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

#define N 100
employee listEmployee[N];
void inputListEmployee(employee *ptr, int n);
void outputListEmployee(employee *ptr, int n);

void inputListEmployee(employee *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout << "\nNV" << i;
        cout << "\tHo: ";
        fflush(stdin);
        gets((ptr + i)->hoten.ho); // = (*ptr).hoten.ho
        cout << "\tTen dem: ";
        gets((ptr + i)->hoten.tendem);
        cout << "\tTen: ";
        gets((ptr + i)->hoten.ten);
        cout << "\tNgay sinh (dd/mm/yyy): ";
        // cin.ignore();
        fflush(stdin);
        cin >> (ptr + i)->ngaysinh.day;
        cin >> (ptr + i)->ngaysinh.month;
        cin >> (ptr + i)->ngaysinh.year;
        cout << "\tQue quan: ";
        fflush(stdin);
        gets((ptr + i)->quequan);
        cout << "\tNgay vao lam (dd/mm/yyy): ";
        fflush(stdin);
        cin >> (ptr + i)->ngayvaolam.day;
        cin >> (ptr + i)->ngayvaolam.month;
        cin >> (ptr + i)->ngayvaolam.year;
        cout << "\tLuong: ";
        cin >> (ptr + i)->luong;
    }
}

void outputListEmployee(employee *ptr, int n)
{
    cout << "\n\tHO VA TEN \t||\tNGAY SINH \t||\tQUE QUAN \t||\tNGAY VAO LAM \t||\tLUONG" << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "    " << (ptr + i)->hoten.ho << " " << (ptr + i)->hoten.tendem << " " << (ptr + i)->hoten.ten << "\t||\t" << (ptr + i)->ngaysinh.day << "/" << (ptr + i)->ngaysinh.month << "/" << (ptr + i)->ngaysinh.year << "\t||\t" << (ptr + i)->quequan << "\t||\t " << (ptr + i)->ngayvaolam.day << "/" << (ptr + i)->ngayvaolam.month << "/" << (ptr + i)->ngayvaolam.year << "\t||\t" << (ptr + i)->luong << endl;
        // cout << "   " << *(ptr + i).hoten.ho << " " << *(ptr + i).hoten.tendem << " " << *(ptr + i).hoten.ten << "\t||\t" << *(ptr + i).ngaysinh.day << "/" << *(ptr + i).ngaysinh.month << "/" << *(ptr + i).ngaysinh.year << "\t||\t" << *(ptr + i).quequan << "\t\t||\t" << *(ptr + i).ngayvaolam.day << "/" << *(ptr + i).ngayvaolam.month << "/" << *(ptr + i).ngayvaolam.year << "\t||\t" << *(ptr + i).luong << endl;
    }
}

int main()
{

    employee *ptr;
    ptr = listEmployee; // = &listEmployee[0]
    int n;
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

    cout << "NHAP CHI TIET THONG TIN NHAN VIEN" << endl;
    inputListEmployee(ptr, n);
    cout << "\nTHONG TIN NHAN VIEN" << endl;
    outputListEmployee(ptr, n);

    return 0;
}
