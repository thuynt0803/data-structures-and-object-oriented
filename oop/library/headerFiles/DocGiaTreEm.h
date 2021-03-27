#pragma once
#include <iostream>
#include <string>
#include "DocGia.h"
/*
* Su dung thu vien co san cua c++ --> < >
* Su dung thu vien do nguoi dung tao --> " "
*/

using namespace std;

class DocGiaTreEm : public DocGia
{
private:
    string hotenNDD;

public:
    void inputInfo();
    void outputInfo();
    int tinhTienLamThe();
    DocGiaTreEm(/* args */);
    ~DocGiaTreEm();
};

