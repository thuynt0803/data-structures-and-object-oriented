#pragma once
#include "DocGiaTreEm.h"
#include "DocGiaNguoiLon.h"
#include <vector>

class Library
{
private:
    vector<DocGiaTreEm> ds_DocGiaTreEm;
    vector<DocGiaNguoiLon> ds_DocGiaNguoiLon;

public:
    void inputInfo();
    void outputInfo();
    int tongTienLamThe();

    Library(/* args */);
    ~Library();
};


