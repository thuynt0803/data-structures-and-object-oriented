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

struct doanhnghiep
{
    char madn[30];
    char giamdoc[30];
    float vondieule;
    int sonhanvien;
};

void input1DN(doanhnghiep &dn)
{
    cout << "Ma DN: ";
    fflush(stdin); //xoa bo nho dem
    gets(dn.madn);
    cout << "Giam doc: ";
    gets(dn.giamdoc);
    cout << "Von dieu le: ";
    fflush(stdin);
    cin >> dn.vondieule;
    cout << "So nhan vien: ";
    cin >> dn.sonhanvien;
}

void output1DN(doanhnghiep dn)
{
    cout << "\n\nMADN: " << dn.madn << endl;
    cout << "GIAM DOC: " << dn.giamdoc << endl;
    cout << "VON: " << dn.vondieule << endl;
    cout << "SO NV: " << dn.sonhanvien << endl;
}

void inputListDN(doanhnghiep ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        input1DN(ds[i]);
        cout << endl;
    }
}

void outputListDN(doanhnghiep ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        output1DN(ds[i]);
    }
}

void sortbyVon(doanhnghiep ds[], int n) // su dung giai thuat sx noi bot
{
    doanhnghiep tg; // tg = trung gian
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i].vondieule > ds[j].vondieule)
            {
                tg = ds[i];
                ds[i] = ds[j];
                ds[j] = tg;
            }
        }
    }
}

void printDN(doanhnghiep dn)
{
    cout << "Ma DN: " << dn.madn << endl;
    cout << "So NV: " << dn.sonhanvien << endl;
}

void printMaDN(doanhnghiep ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ds[i].sonhanvien > 300 && ds[i].madn[0] == 'D' && ds[i].madn[1] == 'N')
        {
            printDN(ds[i]);
        }
    }
}

int checkInvalid(char madn[])
{
    for (int i = 0; i < strlen(madn); i++)
    {
        if (madn[i] == ' ')
            return 1;
    }
    return 0;
}

void countInvalid(doanhnghiep ds[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i].vondieule < 10 || checkInvalid(ds[i].madn) == 1)
        {
            dem++;
        }
    }
    cout << "\nSo DN khong hop le (MaDn chua it nhat 1 dau cach || von dieu le < 10): " << dem << endl;
}

int main()
{
    doanhnghiep listDN[50];
    int n;
    cout << "Nhap so DN: n = ";
    cin >> n;
    cout << endl;

    inputListDN(listDN, n);
    cout << "Danh sach doanh nghiep vua nhap la:" << endl;
    outputListDN(listDN, n);

    sortbyVon(listDN, n);
    cout << "\nDanh sach doanh nghiep sau khi sap xep tang dan theo von dieu le:" << endl;
    outputListDN(listDN, n);

    cout << "\nDoanh nghiep co tren 300 NV va ma DN bat dau la 'DN':" << endl;
    printMaDN(listDN, n);

    countInvalid(listDN, n);
}