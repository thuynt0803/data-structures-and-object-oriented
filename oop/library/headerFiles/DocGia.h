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

public:
    void inputInfo();
    void outputInfo();

    DocGia(/* args */);
    ~DocGia();
};

