#include "./headerFiles/DocGia.h"
#include <iostream>
using namespace std;

//Gọi phương thức từ 1 class ra bên ngoài
// <Kiểu dữ liệu> <tên lớp>::<T.tính hay P.Thức cần gọi ra>
// :: -> thuộc

void DocGia::inputInfo()
{
    fflush(stdin);
    cout << "\nHo ten doc gia: ";
    getline(cin, hoten);
    cout << "Ngay lap the (dd/mm/yyyy): ";
    getline(cin, ngaylapthe);
    fflush(stdin);
    cout << "So thang co hieu luc: ";
    cin >> sothanghieuluc;
}

void DocGia::outputInfo()
{
    cout << "\nHo ten doc gia: " << hoten << endl;
    cout << "Ngay lap the: " << ngaylapthe << endl;
    cout << "So thang co hieu luc: " << sothanghieuluc << endl;
}

DocGia::DocGia(/* args */)
{
}

DocGia::~DocGia()
{
}