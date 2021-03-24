#include <iostream>
using namespace std;

class SinhVien
{
private:
    // thuộc tính
    string masv;
    string tensv;
    float diemtoan;
    float diemly;

public:
    // phương thức
    void inputSV();
    void outputSV();

    // cơ chế đóng gói SETTER - GETTER: hỗ trợ phá vỡ tính chất đóng gói của class, cho phép truy xuất các thuộc tính private từ bên ngoài class
    // mang tính chất chủ động của người dùng

    string getter_hoten()
    {
        return tensv;
    }

    void setter_hoten(string HOTEN)
    {
        tensv = HOTEN;
    }

    // hàm tạo và hàm hủy
    SinhVien();
    ~SinhVien();
};

void SinhVien::inputSV()
{
    cout << "\tNhap MSV: ";
    getline(cin, masv);
    cout << "\tHo ten: ";
    getline(cin, tensv);
    cout << "\tDiem toan: ";
    fflush(stdin);
    cin >> diemtoan;
    cout << "\tDiem ly: ";
    cin >> diemly;
}

void SinhVien::outputSV()
{
    cout << masv << " - " << tensv << " - Diem toan: " << diemtoan << " - Diem ly: " << diemly << endl;
}

SinhVien::SinhVien()
{
}
SinhVien::~SinhVien()
{
}

int main()
{
    SinhVien a;

    cout << "NHAP THONG TIN SINH VIEN" << endl;
    a.inputSV();
    // cout << a.getter_hoten();
    // a.setter_hoten("Nguyen Huy Thanh");

    cout << "\nTHONG TIN SINH VIEN\n"
         << endl;
    a.outputSV();

    return 0;
}