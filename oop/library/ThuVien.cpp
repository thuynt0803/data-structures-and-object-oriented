#include <iostream>
#include "./headerFiles/ThuVien.h"

using namespace std;

// input thong tin cac loai doc gia
void Library::inputInfo()
{
    int luachon;
    while (true)
    {
        system("cls"); // xoa het data man hinh console truoc lenh nay
        cout << "\n\n\t\t ========================= MY LIBRARY =========================" << endl;
        cout << "\n\t 1. Doc gia tre em";
        cout << "\n\t 2. Doc gia nguoi lon";
        cout << "\n\t 0. Thoat";
        cout << "\n\n\t\t ============================= END ============================" << endl;

        cout << "\nNhap lua chon cua ban: ";
        cin >> luachon;

        if (luachon == 1)
        {
            DocGiaTreEm x; //khai bao doi tuong DGTE - de nhap thong tin
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA TRE EM" << endl;
            x.inputInfo();
            ds_DocGiaTreEm.push_back(x); // them doi tuong DGTE x vao trong mang vector DGTE
        }
        else if (luachon == 2)
        {
            DocGiaNguoiLon x; //khai bao doi tuong DGTE - de nhap thong tin
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA NGUOI LON" << endl;
            x.inputInfo();
            ds_DocGiaNguoiLon.push_back(x); // them doi tuong DGTE x vao trong mang vector DGTE
        }
        else if (luachon == 0)
        {
            break;
        }
        else
        {
            cout << "\nNOTE: Lua chon duoc nhap khong hop le, vui long nhap lai!";
            system("pause");
        }
    }
}

// phuong thuc xuat thong tin doc gia
void Library::outputInfo()
{
    // xuat thong tin Doc gia tre em
    cout << "\n\n\t\t THONG TIN DANH SACH DOC GIA TRE EM" << endl;
    for (int i = 0; i < ds_DocGiaTreEm.size(); i++) // ds_DocGiaTreEm.size() - so luong phan tu hien co trong ds DGTE
    {
        ds_DocGiaTreEm[i].outputInfo();
    }

    // xuat thong tin Doc gia nguoi lon
    cout << "\n\n\t\t THONG TIN DANH SACH DOC GIA NGUOI LON" << endl;
    for (int i = 0; i < ds_DocGiaNguoiLon.size(); i++) // ds_DocGiaTreEm.size() - so luong phan tu hien co trong ds DGTE
    {
        ds_DocGiaNguoiLon[i].outputInfo();
    }
}

// Phuong thuc tinh tong tien lam the
int Library::tongTienLamThe()
{
    int sum = 0;
    // duyet danh sach DGTE
    for (int i = 0; i < ds_DocGiaTreEm.size(); i++)
    {
        sum += ds_DocGiaTreEm[i].tinhTienLamThe();
    }

    // duyet danh sach DGNL
    for (int i = 0; i < ds_DocGiaNguoiLon.size(); i++)
    {
        sum += ds_DocGiaNguoiLon[i].tinhTienLamThe();
    }
    return sum;
}

Library::Library(/* args */)
{
}

Library::~Library()
{
}