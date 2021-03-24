#include <iostream>
#include <string>

using namespace std;

class employee
{
protected:
    string name;
    string address;
    string phone;

public:
    void inputEmployee()
    {
        fflush(stdin);
        cout << "\nHo ten: ";
        getline(cin, name);
        cout << "Dia chi: ";
        getline(cin, address);
        cout << "SDT: ";
        getline(cin, phone);
    }

    void outputEmployee()
    {
        cout << "\tHo & ten\t\t";
        cout << "\n   " << name << "\t||\t   " << address << "\t||\t   " << phone;
    }
};

class employeeSON : public employee
{
private:
    float repairTime;

public:
    void inputEmployee()
    {
        employee::inputEmployee();
        fflush(stdin);
        cout << "So gio sua: ";
        cin >> repairTime;
    }

    float salary()
    {
        return repairTime * 100000;
    }

    void outputEmployee()
    {
        employee::outputEmployee();
        cout << "\t||\t   " << repairTime << "\t||\t   " << (size_t)salary();
    }
};

class employeeGH : public employee
{
private:
    int packageNumber;

public:
    void inputEmployee()
    {
        employee::inputEmployee();
        fflush(stdin);
        cout << "So hang giao: ";
        cin >> packageNumber;
    }

    int salary()
    {
        return packageNumber * 50000;
    }

    void outputEmployee()
    {
        employee::outputEmployee();
        cout << "\t||\t   " << packageNumber << "\t||\t   " << (size_t)salary();
    }
};

class employeeXO : public employee
{
private:
    float kmNumber;

public:
    void inputEmployee()
    {
        employee::inputEmployee();
        fflush(stdin);
        cout << "So km van chuyen: ";
        cin >> kmNumber;
    }

    float salary()
    {
        return kmNumber * 10000;
    }

    void outputEmployee()
    {
        employee::outputEmployee();
        cout << "\t||\t   " << kmNumber << "\t||\t   " << (size_t)salary();
    }
};

// Tong luong nv sua ong nuoc
double totalSalary(employeeSON *list_NVSON[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += list_NVSON[i]->salary();
    }
    return sum;
}

// Tong luong nv giao hang
double totalSalary(employeeGH *list_NVGH[], int m)
{
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += list_NVGH[i]->salary();
    }
    return sum;
}

// Tong luong nv xe om cong nghe
double totalSalary(employeeXO *list_NVXO[], int l)
{
    double sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += list_NVXO[i]->salary();
    }
    return sum;
}

// Sap xep dsnv sua ong nuoc giam dan theo luong
void salaryReductionSON(employeeSON *list_NVSON[], int n)
{
    employeeSON *temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (list_NVSON[i]->salary() < list_NVSON[j]->salary())
            {
                temp = list_NVSON[i];
                list_NVSON[i] = list_NVSON[j];
                list_NVSON[j] = temp;
            }
        }
    }
}

// Sap xep dsnv giao hang giam dan theo luong
void salaryReductionGH(employeeGH *list_NVGH[], int m)
{
    employeeGH *temp;
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (list_NVGH[i]->salary() < list_NVGH[j]->salary())
            {
                temp = list_NVGH[i];
                list_NVGH[i] = list_NVGH[j];
                list_NVGH[j] = temp;
            }
        }
    }
}

// Sap xep dsnv xe om cong nghe giam dan theo luong
void salaryReductionXO(employeeXO *list_NVXO[], int l)
{
    employeeXO *temp;
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (list_NVXO[i]->salary() < list_NVXO[j]->salary())
            {
                temp = list_NVXO[i];
                list_NVXO[i] = list_NVXO[j];
                list_NVXO[j] = temp;
            }
        }
    }
}

void menu(employeeSON *list_NVSON[], int n, employeeGH *list_NVGH[], int m, employeeXO *list_NVXO[], int l)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t =============== QUAN LY NHAN VIEN ===============\n"
             << endl;
        cout << "\t1. Nhap thong tin nhan vien sua ong nuoc" << endl;
        cout << "\t2. Nhap thong tin nhan vien giao hang" << endl;
        cout << "\t3. Nhan thong tin nhan vien xe om cong nghe" << endl;
        cout << "\t4. Xuat danh sach thong tin nhan vien sua ong nuoc" << endl;
        cout << "\t5. Xuat danh sach thong tin nhan vien giao hang" << endl;
        cout << "\t6. Xuat danh sach thong tin nhan vien xe om cong nghe" << endl;
        cout << "\t7. Tong tien luong phai tra cho tat ca nhan vien" << endl;
        cout << "\t8. Sap xep danh sach cac loai nhan vien giam dan theo luong" << endl;
        cout << "\t0. Ket thuc" << endl;
        cout << "\n\t\t ====================== END ======================";

        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 8)
        {
            cout << "\n*NOTE: Lua chon khong hop le, vui long nhap lai.";
        }
        else if (luachon == 0)
        {
            break;
            system("pause");
        }
        else if (luachon == 1)
        {
            employeeSON *nv_son = new employeeSON(); // doi tuong con tro
            cout << "\n\t\t NHAP THONG TIN NHAN VIEN SUA ONG NUOC" << endl;
            nv_son->inputEmployee();
            // them doi tuong con tro "nv_son" vao danh sach con tro list
            list_NVSON[n] = nv_son;
            n++;
        }
        else if (luachon == 2)
        {
            employeeGH *nv_gh = new employeeGH(); // doi tuong con tro
            cout << "\n\t\t NHAP THONG TIN NHAN VIEN GIAO HANG" << endl;
            nv_gh->inputEmployee();
            list_NVGH[m] = nv_gh;
            m++;
        }
        else if (luachon == 3)
        {
            employeeXO *nv_xo = new employeeXO(); // doi tuong con tro
            cout << "\n\t\t NHAP THONG TIN NHAN VIEN XE OM CONG NGHE" << endl;
            nv_xo->inputEmployee();
            list_NVXO[l] = nv_xo;
            l++;
        }
        else if (luachon == 4)
        {
            cout << "\n\t\t DANH SACH THONG TIN NHAN VIEN SUA ONG NUOC" << endl;
            for (int i = 0; i < n; i++)
            {
                list_NVSON[i]->outputEmployee();
            }
            cout << "\n==> TONG TIEN LUONG PHAI TRA: " << (size_t)totalSalary(list_NVSON, n);
            system("pause");
        }
        else if (luachon == 5)
        {
            cout << "\n\n\t\t DANH SACH THONG TIN NHAN VIEN GIAO HANG" << endl;
            for (int i = 0; i < m; i++)
            {
                list_NVGH[i]->outputEmployee();
            }
            cout << "\n==> TONG TIEN LUONG PHAI TRA: " << (size_t)totalSalary(list_NVGH, m);
            system("pause");
        }
        else if (luachon == 6)
        {
            cout << "\n\n\t\t DANH SACH THONG TIN NHAN VIEN XE OM CONG NGHE" << endl;
            for (int i = 0; i < l; i++)
            {
                list_NVXO[i]->outputEmployee();
            }
            cout << "\n==> TONG TIEN LUONG PHAI TRA: " << (size_t)totalSalary(list_NVXO, l);
            system("pause");
        }
        else if (luachon == 7)
        {
            cout << "\n\t TONG TIEN LUONG CONG TY CAN TRA HANG THANG CHO TOAN BO NHAN VIEN = " << (size_t)(totalSalary(list_NVSON, n) + totalSalary(list_NVGH, m) + totalSalary(list_NVXO, l)) << endl;
            system("pause");
        }
        else if (luachon == 8)
        {
            cout << "\n\n\t\t DANH SACH NHAN VIEN SUA ONG NUOC GIAM DAN THEO LUONG" << endl;
            salaryReductionSON(list_NVSON, n);
            for (int i = 0; i < n; i++)
            {
                list_NVSON[i]->outputEmployee();
            }

            cout << "\n\n\t\t DANH SACH NHAN VIEN GIAO HANG GIAM DAN THEO LUONG" << endl;
            salaryReductionGH(list_NVGH, m);
            for (int i = 0; i < m; i++)
            {
                list_NVGH[i]->outputEmployee();
            }

            cout << "\n\n\t\t DANH SACH NHAN VIEN XE OM CONG NGHE GIAM DAN THEO LUONG" << endl;
            salaryReductionXO(list_NVXO, l);
            for (int i = 0; i < l; i++)
            {
                list_NVXO[i]->outputEmployee();
            }

            system("pause");
        }
        else
            break;
    }

    // giai phong cac doi tuong con tro cho danh sach nv sua ong nuoc
    for (int i = 0; i < n; i++)
    {
        delete list_NVSON[i];
    }
    // giai phong cac doi tuong con tro cho danh sach nv giao hang
    for (int i = 0; i < m; i++)
    {
        delete list_NVGH[i];
    }
    // giai phong cac doi tuong con tro cho danh sach nv xe om cong nghe
    for (int i = 0; i < l; i++)
    {
        delete list_NVXO[i];
    }
}

int main()
{
    /* Khai bao danh sach chua toi da 100 doi tuong con tro -> Moi o nho la mot con tro */
    employeeSON *list_NVSON[100];
    employeeGH *list_NVGH[100];
    employeeXO *list_NVXO[100];
    int n = 0;
    int m = 0;
    int l = 0;

    menu(list_NVSON, n, list_NVGH, m, list_NVXO, l);

    system("pause");
    return 0;
}