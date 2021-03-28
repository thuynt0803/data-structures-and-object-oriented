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

        DocGia *x; // khai báo con trỏ lớp cha
        if (luachon == 1)
        {
            x = new DocGiaTreEm; // dùng x để new ra 1 đối tượng con là DocGiaTreEm
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA TRE EM" << endl;
            x->inputInfo();
            x->Setter_KT(true);     // Đánh dấu x là độc giả trẻ em
            ds_DocGia.push_back(x); // thêm một đối tượng con vào mảng DocGia
        }
        else if (luachon == 2)
        {
            x = new DocGiaNguoiLon; // dùng x để new ra 1 đối tượng con là DocGiaNguoiLon
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA NGUOI LON" << endl;
            x->inputInfo();
            x->Setter_KT(false);    // Đánh dấu x là độc giả người lớn
            ds_DocGia.push_back(x); // thêm một đối tượng con vào mảng DocGia
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
    // xuat thong tin Doc gia
    cout << "\n\n\t\t ======= DANH SACH DOC GIA =======" << endl;
    for (int i = 0; i < ds_DocGia.size(); i++) // ds_DocGia.size() - so luong phan tu hien co trong ds_DocGia
    {
        if (ds_DocGia[i]->Getter_KT() == true)
        {
            cout << "\nDoc gia tre em " << i + 1;
            ds_DocGia[i]->outputInfo();
        }
        else
        {
            cout << "\nDoc gia nguoi lon " << i + 1;
            ds_DocGia[i]->outputInfo();
        }
    }
}

// Phuong thuc tinh tong tien lam the
int Library::tongTienLamThe()
{
    int sum = 0;
    // duyet danh sach DocGia
    for (int i = 0; i < ds_DocGia.size(); i++)
    {
        sum += ds_DocGia[i]->tinhTienLamThe();
    }
    return sum;
}

Library::Library(/* args */)
{
}

Library::~Library()
{
}