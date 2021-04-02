/*
    Cho cây nhị phân tìm kiếm các số nguyên. Đếm số nguyên tố có trong cây
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
typedef NODE *TREE;

void initTree(TREE &t)
{
    t = NULL;
}

void addNumbersToTheTree(TREE &t, int x)
{
    if (t == NULL)
    {
        NODE *p = new NODE;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        t = p;
    }
    else
    {
        if (t->data > x)
        {
            addNumbersToTheTree(t->left, x);
        }
        else if (t->data < x)
        {
            addNumbersToTheTree(t->right, x);
        }
    }
}

void outputRNL(TREE t)
{
    if (t != NULL)
    {
        outputRNL(t->right);
        cout << t->data << "  ";
        outputRNL(t->left);
    }
}

bool checkPrime(int x)
{
    if (x < 2)
    {
        return false;
    }
    else
    {
        if (x == 2)
        {
            return true;
        }
        else
        {
            if (x % 2 == 0)
            {
                return false;
            }
            else
            {
                for (int i = 2; i < x; i++)
                {
                    if (x % i == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int dem;
void numberPrimes(TREE t, int &dem)
{
    if (t != NULL)
    {
        numberPrimes(t->right, dem);
        //xu ly
        if (checkPrime(t->data) == true)
        {
            dem++;
        }
        numberPrimes(t->left, dem);
    }
}

/*
if (x < 2)
    {
        cout << "\t==> " << x << " is not a prime number." << endl;
        return 0;
    }

    int i, countX = 0;
    for (i = 2; i <= (int(sqrt(x))); i++)
    {
        if (x % i == 0)
        {
            countX++;
        }
    }

    if (countX == 0)
    {
        cout << "\t==> " << x << " is a prime number." << endl;
    }
    else
        cout << "\t==> " << x << " is not a prime number." << endl;
*/

// dem so luong SNT

void menu(TREE &t)
{
    while (true)
    {
        cout << "\n\n\t\t================== MENU ==================" << endl;
        cout << "\t1. Nhap phan tu vao cay" << endl;
        cout << "\t2. Xuat du lieu cay theo RNL" << endl;
        cout << "\t3. Danh sach so nguyen to trong cay nhi phan" << endl;
        cout << "\t0. Thoat";
        cout << "\n\n\t\t================== END ==================" << endl;

        int select;
        cout << "\n==> Nhap lua chon cua ban? - ";
        cin >> select;

        if (select < 0 || select > 3)
        {
            cout << "\nNOTE: Lua chon khong hop le, vui long chon lai!" << endl;
            system("pause");
        }

        if (select == 1)
        {
            int x;
            cout << "\nNhap so nguyen x = ";
            cin >> x;
            addNumbersToTheTree(t, x);
        }
        else if (select == 2)
        {
            cout << "\nDanh sach khi duyet cay theo co che RNL: ";
            outputRNL(t);
            cout << endl;
            system("pause");
        }
        else if (select == 3)
        {
            int dem = 0;
            numberPrimes(t, dem);
            cout << "\nSo luong so nguyen to la: " << dem;
            cout << endl;
            system("pause");
        }
        else
            break;
    }
}

int main()
{
    TREE t;
    initTree(t);
    menu(t);

    system("pause");
    return 0;
}