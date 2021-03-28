#pragma once // tránh tình trạng đụng độ thư viện - trong mọi tình huống chỉ có 1 thư viện được tạo ra ở tất cả các file

#include <iostream>
#include <string>

using namespace std;

class DocGia
{
protected:
    string hoten;
    string ngaylapthe; // dd-mm-yyyy
    int sothanghieuluc;
    bool KT; // true : tre em, false : nguoi lon

public:
    virtual void inputInfo();
    virtual void outputInfo();
    virtual int tinhTienLamThe() = 0; // khai báo phương thức thuần ảo - các lớp con kế thừa sẽ đi định nghĩa

    /* GETTER_SETTER KT*/
    // Tra ve du lieu
    bool Getter_KT()
    {
        return KT;
    }
    
    // Cap nhat du lieu
    void Setter_KT(bool kt)
    {
        KT = kt;
    }

    DocGia(/* args */);
    ~DocGia();
};
