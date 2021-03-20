/*
    Yêu cầu:
        - Nhập n Doanhnghiep (maDN, giamdoc, vondieule, soNV)
        - Sắp xếp danh sách theo chiều tăng dần của vốn
        - Xuất danh sách n DN ra màn hình
        - Input mã DN, số NV (if maNV bắt đầu bằng 'DN' và > 300 nhân viên)
        - Đếm số DN không hợp lệ (Mã DN chứa ít nhất một dấu cách || vốn điều lệ < 10)
*/

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

struct company
{
    char idDN[30];
    char manager[30];
    float capital;
    int employees;
};

void inputOneDN(company &dn)
{
    cout << "Ma DN: ";
    fflush(stdin); //xoa bo nho dem
    gets(dn.idDN);
    cout << "Giam doc: ";
    gets(dn.manager);
    cout << "Von dieu le: ";
    fflush(stdin);
    cin >> dn.capital;
    cout << "So nhan vien: ";
    cin >> dn.employees;
}

void outputOneDN(company dn)
{
    cout << "\n\nMA DN: " << dn.idDN << endl;
    cout << "GIAM DOC: " << dn.manager << endl;
    cout << "VON: " << dn.capital << endl;
    cout << "SO NV: " << dn.employees << endl;
}

void inputListDN(company ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        inputOneDN(ds[i]);
        cout << endl;
    }
}

void outputListDN(company ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        outputOneDN(ds[i]);
    }
}

void sortByCapital(company ds[], int n) // SX tăng dần vốn, sử dụng thuật toán sắp xếp nổi bọt
{
    company tg; // tg = trung gian
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i].capital > ds[j].capital)
            {
                tg = ds[i];
                ds[i] = ds[j];
                ds[j] = tg;
            }
        }
    }
}

void printDN(company dn)
{
    cout << "Ma DN: " << dn.idDN << endl;
    cout << "So NV: " << dn.employees << endl;
}

void printMaDN(company ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ds[i].employees > 300 && ds[i].idDN[0] == 'D' && ds[i].idDN[1] == 'N')
        {
            printDN(ds[i]);
        }
    }
}

int checkInvalid(char idDN[])
{
    for (int i = 0; i < strlen(idDN); i++)
    {
        if (idDN[i] == ' ')
            return 1;
    }
    return 0;
}

void countInvalid(company ds[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i].capital < 10 || checkInvalid(ds[i].idDN) == 1)
        {
            dem++;
        }
    }
    cout << "\nSo DN khong hop le (MaDn chua it nhat 1 dau cach || von dieu le < 10): " << dem << endl;
}

int main()
{
    company listDN[50];
    int n;
    cout << "\nNhap so DN: n = ";
    cin >> n;
    cout << endl;

    inputListDN(listDN, n);
    cout << "Danh sach doanh nghiep vua nhap la:" << endl;
    outputListDN(listDN, n);

    sortByCapital(listDN, n);
    cout << "\nDanh sach doanh nghiep sau khi sap xep tang dan theo von dieu le:" << endl;
    outputListDN(listDN, n);

    cout << "\nDoanh nghiep co tren 300 NV va ma DN bat dau la 'DN':" << endl;
    printMaDN(listDN, n);

    countInvalid(listDN, n);
}