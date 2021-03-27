#include "./headerFiles/DocGia.h"
#include "./headerFiles/DocGiaTreEm.h"

void DocGiaTreEm::inputInfo()
{
    DocGia::inputInfo();
    cin.ignore();
    cout << "Ho ten nguoi dai dien: ";
    getline(cin, hotenNDD);
}

void DocGiaTreEm::outputInfo()
{
    DocGia::outputInfo();
    cout << "Ho ten nguoi dai dien: " << hotenNDD << endl;
}

int DocGiaTreEm::tinhTienLamThe()
{
    return sothanghieuluc * 5000;
}

DocGiaTreEm::DocGiaTreEm(/* args */)
{
}

DocGiaTreEm::~DocGiaTreEm()
{
}