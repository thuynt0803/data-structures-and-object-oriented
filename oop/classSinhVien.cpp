#include <iostream>
using namespace std;

class SinhVien
{
private:
    string masv;
    string tensv;
    int tuoi;

public:
    //phương thức constructor - hàm khởi tạo giá trị mặc định cho biến ở trong class
    SinhVien()
    {
        masv = "17D190032";
        tensv = "Nguyen Thi Thu Thuy";
        tuoi = 22;
    }
    void noiChuyen()
    {
        cout << "Thao luan nhom." << endl;
    }
    void choiGame()
    {
        cout << "Lien minh huyen thoai." << endl;
    }
    void hocBai()
    {
        cout << "Lap trinh huong doi tuong." << endl;
    }
    void inthongtin()
    {
        cout << "Thong tin sinh vien: " << masv << "-" << tensv << "-" << tuoi << endl;
    }
};

int main()
{
    SinhVien a;
    a.inthongtin();
    a.choiGame();
    a.hocBai();

    return 0;
}