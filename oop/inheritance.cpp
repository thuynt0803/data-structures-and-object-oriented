/* 
DEMO TINH KE THUA TRONG HUONG DOI TUONG
    De bai: Loai xe cho thue: xe dap, xe may. Trong do:
        - xe dap: ho ten nguoi thue, so gio thue,
                  tien thue xe dap: 10000d cho gio dau, 8000 cho moi gio tiep theo
        - xe may: ho ten nguoi thue, so gio thue, loai xe(100 phan khoi, 250 phan khoi), bien so.
                  tien thue xe may: gio dau: 150000d - xe 100 pk; 200000d - xe 250 pk
                                    gio tiep theo: 100000 cho ca 2 loai xe
    
    Yeu cau:
        1. XD cac class can thiet, nhap danh sach thong tin thue xe
        2. Xuat thong tin thue xe (bao gom ca tien thue)
        3. Tinh tong so tien cho thue xe dap va xe may
        4. Xuat tat ca thong tin lien quan den viec thue xe dap
        5. Tinh tong so tien cho thue xe may loai 250 phan khoi
*/

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
        cout << "\nSo gio thue: ";
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
        cout << "\nLoai xe muon thue: ";
        cin >> loaixe;
        fflush(stdin);
        cout << "\nBien xe: ";
        getline(cin, bienso);
    }

    void outputInfo()
    {
        XE::outputInfo();
        cout << "\nLoai xe: " << loaixe << endl;
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
};

// phuong thuc xuat tat ca thong tin thue xe
void ouputAllInfor(XeDap ds_xedap[], int n, XeMay ds_xemay[], int m)
{
    cout << "\n\n\t\t DANH SACH THUE XE DAP" << endl;
    for (int i = 0; i < n; i++)
    {
        ds_xedap[i].outputInfo();
        cout << "\nTien thue: " << ds_xedap[i].tinhTienThue();
    }

    cout << "\n\n\t\t DANH SACH THUE XE MAY" << endl;
    for (int i = 0; i < m; i++)
    {
        ds_xemay[i].outputInfo();
        cout << "\nTien thue: " << ds_xemay[i].tinhTienThue();
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
        cout << "\n\n\t\t =============== QUAN LY THUE XE ===============" << endl;
        cout << "\t1. Nhap danh sach thue xe dap va xe may" << endl;
        cout << "\t2. Xuat tat ca thong tin thue xe" << endl;
        cout << "\t3. Tinh tong so tien cho thue xe dap va xe may" << endl;
        cout << "\t4. Xuat tat ca cac thong tin lien quan den viec cho thue xe dap" << endl;
        cout << "\t5. Tinh tong so tien cho thue xe may loai 250 phan khoi" << endl;
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
            cout << "\n\n\t\tTong tien thue xe la: " << totalRent(ds_xedap, n, ds_xemay, m) << endl;
            system("pause");
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