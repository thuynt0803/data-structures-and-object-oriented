#include "./headerFiles/DocGiaNguoiLon.h"

void DocGiaNguoiLon::inputInfo()
{
    DocGia::inputInfo();
    cin.ignore();
    cout << "CMND: ";
    getline(cin, CMND);
}

void DocGiaNguoiLon::outputInfo()
{
    DocGia::outputInfo();
    cout << "Chung minh nhan dan: " << CMND << endl;
}

int DocGiaNguoiLon::tinhTienLamThe()
{
    return sothanghieuluc * 10000;
}

DocGiaNguoiLon::DocGiaNguoiLon(/* args */)
{
}

DocGiaNguoiLon::~DocGiaNguoiLon()
{
}