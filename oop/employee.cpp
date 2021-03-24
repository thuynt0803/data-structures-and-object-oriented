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
        cout << "\nDia chi: ";
        getline(cin, address);
        cout << "\nSDT: ";
        getline(cin, phone);
    }

    void outputEmployee()
    {
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
        cout << "\nSo gio sua: ";
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
        cout << "\nSo hang giao: ";
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
        cout << "\nSo km van chuyen: ";
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

int main()
{

    system("pause");
    return 0;
}