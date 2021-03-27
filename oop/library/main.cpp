#include "./headerFiles/ThuVien.h"

int main()
{
    Library *x = new Library;
    x->inputInfo();
    x->outputInfo();

    cout << "\n\t\t TONG TIEN LAM THE: " << x->tongTienLamThe() << endl;
    delete x;
    system("pause");
    return 0;
}