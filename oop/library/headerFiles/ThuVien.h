#pragma once
#include "DocGiaTreEm.h"
#include "DocGiaNguoiLon.h"
#include <vector>

class Library
{
private:
    vector<DocGia *> ds_DocGia; // Áp dụng tính đa hình, khai báo mạng 1 chiều chứa lớp cha - vì có virtual --> đa hình sang từng thằng con tương ứng.

public:
    void inputInfo();
    void outputInfo();
    int tongTienLamThe();

    Library(/* args */);
    ~Library();
};
