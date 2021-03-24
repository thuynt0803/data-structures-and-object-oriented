#include <iostream>
#include <string> 
using namespace std;

class XE
{
protected:
    string hotennguoithue;
    float sogiothue;

public:
    void inputInfo()
    {
        fflush(stdin);
        cout << "\nHo ten nguoi thue xe: ";
        getline(cin, hotennguoithue);
        fflush(stdin);
        cout << "So gio thue: ";
        cin >> sogiothue;
    }

    void outputInfo()
    {
        cout << "\nNguoi thue: " << hotennguoithue << endl;
        cout << "Gio thue: " << sogiothue << endl;
    }
};

class XeDap : public XE
{
private:
public:
    float tinhTienThue()
    {
        return 10000 + ((sogiothue - 1) * 8000);
    }
};

class XeMay : public XE
{
private:
    int loaixe;
    string bienso;

public:
    void inputInfo()
    {
        XE::inputInfo();
        cout << "Loai xe muon thue (100/250 phan khoi): ";
        cin >> loaixe;
        fflush(stdin);
        cout << "Bien xe: ";
        getline(cin, bienso);
    }

    void outputInfo()
    {
        XE::outputInfo();
        cout << "Loai xe: " << loaixe << endl;
        cout << "Bien so xe: " << bienso << endl;
    }

    float tinhTienThue()
    {
        float s = 0;
        if (loaixe == 100)
        {
            s = 150000;
        }
        else
            s = 200000;
        return s + ((sogiothue - 1) * 100000);
    }

    //GETTER - Loai xe
    int getterLoaiXe()
    {
        return loaixe;
    }

    void setterLoaiXe(int LOAIXE)
    {
        loaixe = LOAIXE;
    }
};

// phuong thuc xuat tat ca thong tin thue xe
void ouputAllInfor(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m)
{
    cout << "\n\n\t\t DANH SACH THUE XE DAP" << endl;
    for (int i = 0; i < n; i++)
    {
        ds_xedap[i].outputInfo();
        cout << "Tien thue: " << (size_t)ds_xedap[i].tinhTienThue();
    }

    cout << "\n\n\t\t DANH SACH THUE XE MAY" << endl;
    for (int i = 0; i < m; i++)
    {
        ds_xemay[i].outputInfo();
        cout << "Tien thue: " << (size_t)ds_xemay[i].tinhTienThue() << endl;
    }
}

// phuong thuc tinh tong tien thue xe dap va xe may
float totalRent(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m)
{
    float tong = 0;
    //duyet danh sach xe dap
    for (int i = 0; i < n; i++)
    {
        tong += ds_xedap[i].tinhTienThue();
    }

    //duyet danh sach xe may
    for (int i = 0; i < m; i++)
    {
        tong += ds_xemay[i].tinhTienThue();
    }

    return tong;
}

// phuong thuc quan ly thue xe
void menu(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t =============== QUAN LY THUE XE ===============" << endl;
        cout << "\t1. Nhap danh sach thue xe dap va xe may" << endl;
        cout << "\t2. Xuat tat ca thong tin thue xe" << endl;
        cout << "\t3. Tinh tong so tien cho thue xe dap va xe may" << endl;
        cout << "\t4. Tinh tong so tien cho thue xe may loai 250 phan khoi" << endl;
        cout << "\t0. Ket thuc" << endl;
        cout << "\n\n\t\t ====================== END ======================";

        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon == 1)
        {
            int chon;
            while (true)
            {
                system("cls");
                cout << "\n\t\t1. Thue xe dap" << endl;
                cout << "\t\t2. Thue xe may" << endl;
                cout << "\t\t0. Ket thuc" << endl;
                cout << "\nBan muon thue xe gi? - Lua chon: ";
                cin >> chon;

                if (chon == 1)
                {
                    XeDap x;
                    cout << "\n\t\tNHAP THONG TIN THUE XE DAP" << endl;
                    x.inputInfo();
                    ds_xedap[n] = x;
                    n++;
                }
                else if (chon == 2)
                {
                    XeMay x;
                    cout << "\n\t\tNHAP THONG TIN THUE XE MAY" << endl;
                    x.inputInfo();
                    ds_xemay[m] = x;
                    m++;
                }
                else
                    break;
            }
        }
        else if (luachon == 2)
        {
            ouputAllInfor(ds_xedap, n, ds_xemay, m);
            system("pause");
        }
        else if (luachon == 3)
        {
            cout << "\n\tTONG TAT CA TIEN THUE XE = " << size_t(totalRent(ds_xedap, n, ds_xemay, m)) << endl;
            system("pause");
        }
        else if (luachon == 4)
        {
            cout << "\n\t\tDANH SACH THUE XE MAY LOAI 250 PHAN KHOI" << endl;
            for (int i = 0; i < m; i++)
            {
                if (ds_xemay[i].getterLoaiXe() == 250)
                {
                    ds_xemay[i].outputInfo();
                    cout << "Tien thue: " << (size_t)ds_xemay[i].tinhTienThue() << endl;
                }
            }
            system("pause");
        }
        else
        {
            break;
        }
    }
}

int main()
{
    XeDap ds_xedap[50];
    int n = 0;
    XeMay ds_xemay[50];
    int m = 0;

    menu(ds_xedap, n, ds_xemay, m);
    system("pause");
    return 0;
}