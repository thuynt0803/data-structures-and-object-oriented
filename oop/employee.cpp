/*
    Có 3 nhân viên: NV sửa ổng nước, NV giao hàng, NV xe ôm công nghệ
    Yêu cầu:
        1 Mô tả và phân tích các thông tin cần thiết để quản lý các nhân viên trên
        2 Tính tiền lương hàng tháng của 3 nhân viên, biết:
            NV sửa ống nước: lương = số giờ sửa * 100000
            NV giao hàng: lương = số hàng giao * 50000
            NV xe ôm: lương = số km * 10000

        3 Tinh tong tien luong phai tra cho tat ca nhan vien 
        (su dung 'size_t' loai bo truong hop rut gon khi so qua dai)
        4 Thong ke danh sach nhan vien giam dan theo luong
        
*/

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

#define N 50
#define M 50
#define L 50

class NVSuaOngNuoc
{
private:
    string hoten;
    string gioitinh;
    string diachi;
    string sdt;
    float sogiosua;

public:
    void inputNV();
    void outputNV();
    void luong();

    NVSuaOngNuoc();
    ~NVSuaOngNuoc();
};

NVSuaOngNuoc::NVSuaOngNuoc()
{
}

NVSuaOngNuoc::~NVSuaOngNuoc()
{
}

void NVSuaOngNuoc::inputNV()
{
    fflush(stdin);
    cout << "Ho ten: ";
    getline(cin, hoten);
    cout << "Gioi tinh: ";
    getline(cin, gioitinh);
    cout << "Dia chi: ";
    getline(cin, diachi);
    cout << "SDT: ";
    getline(cin, sdt);
    fflush(stdin);
    cout << "So gio sua: ";
    cin >> sogiosua;
}

void NVSuaOngNuoc::outputNV()
{
    cout << "\tHo ten\t\tGioi tinh\t\tDia chi\t\tSDT";
    cout << hoten << "\t\t   " << gioitinh << "\t  " << diachi << "\t   " << sdt << endl;
}

class NVGiaoHang
{
private:
    string hoten;
    string gioitinh;
    string diachi;
    string sdt;
    float sohanggiao;

public:
    void inputNV();
    void outputNV();
    void luong();

    NVGiaoHang();
    ~NVGiaoHang();
};

NVGiaoHang::NVGiaoHang()
{
}

NVGiaoHang::~NVGiaoHang()
{
}

void NVGiaoHang::inputNV()
{
    fflush(stdin);
    cout << "Ho ten: ";
    getline(cin, hoten);
    cout << "Gioi tinh: ";
    getline(cin, gioitinh);
    cout << "Dia chi: ";
    getline(cin, diachi);
    cout << "SDT: ";
    getline(cin, sdt);
}

void NVGiaoHang::outputNV()
{
    cout << "\tHo ten\t\tGioi tinh\t\tDia chi\t\tSDT";
    cout << hoten << "\t\t   " << gioitinh << "\t  " << diachi << "\t   " << sdt << endl;
}

class NVXeOm
{
private:
    string hoten;
    string gioitinh;
    string diachi;
    string sdt;
    float sokm;

public:
    void inputNV();
    void outputNV();
    void luong();

    NVXeOm();
    ~NVXeOm();
};

NVXeOm::NVXeOm()
{
}

NVXeOm::~NVXeOm()
{
}

void NVXeOm::inputNV()
{
    fflush(stdin);
    // một cách khác để xóa bộ nhớ đệm trước khi nhập chuỗi:
    // while(getchar() != '\n'); --> lệnh này thuộc thư viện conio.h
    cout << "Ho ten: ";
    getline(cin, hoten);
    cout << "Gioi tinh: ";
    getline(cin, gioitinh);
    cout << "Dia chi: ";
    getline(cin, diachi);
    cout << "SDT: ";
    getline(cin, sdt);
}

void NVXeOm::outputNV()
{
    cout << "\tHo ten\t\tGioi tinh\t\tDia chi\t\tSDT";
    cout << hoten << "\t\t   " << gioitinh << "\t  " << diachi << "\t   " << sdt << endl;
}

//
void menu(NVSuaOngNuoc listNVSON[], NVGiaoHang listNVGH[], NVXeOm listNVXO[], int n, int m, int l)
{
    int luachon;
    while (true)
    {
        cout << "\n\n\t\t =============== QUAN LY NHAN VIEN ===============";
        cout << "\n1. Nhap thong tin nhan vien SUA ONG NUOC" << endl;
        cout << "\n2. Nhap thong tin nhan vien GIAO HANG" << endl;
        cout << "\n3. Nhap thong tin nhan vien XE OM CONG NGHE";
        cout << "\n\n\t\t ====================== END ======================";

        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon < 0 || luachon > 3)
        {
            cout << "\nLua chon khong hop le. Kiem ta lai!";
        }
        else if (luachon == 0)
        {
            break;
        }

        else if (luachon == 1)
        {
            NVSuaOngNuoc nv_SON; // doi tuong gia tri
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN SUA ONG NUOC" << endl;
            nv_SON.inputNV();

            // them doi tuong gia tri "nv_SON" vao danh sach "listNVSON"
            listNVSON[n] = nv_SON;
            n++;
        }
        else if (luachon == 2)
        {
            NVGiaoHang nv_GH; // doi tuong gia tri
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN GIAO HANG" << endl;
            nv_GH.inputNV();

            // them doi tuong gia tri "nv_GH" vao danh sach "listNVGH"
            listNVGH[m] = nv_GH;
            m++;
        }
        else if (luachon == 3)
        {
            NVXeOm nv_XO; // doi tuong gia tri
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN XE OM CONG NGHE" << endl;
            nv_XO.inputNV();

            // them doi tuong gia tri "nv_XO" vao danh sach "listNVXO"
            listNVXO[L] = nv_XO;
            l++;
        }
    }
}

int main()
{
    NVSuaOngNuoc listNVSON[N];
    NVGiaoHang listNVGH[M];
    NVXeOm listNVXO[L];
    int n, m, l;
    menu(listNVSON, listNVGH, listNVXO, n, m, l);

    NVSuaOngNuoc *nv_son = new NVSuaOngNuoc(); // doi tuong con tro
    nv_son->inputNV();

    delete nv_son;
    return 0;
}