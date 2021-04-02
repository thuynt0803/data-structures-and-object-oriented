/*
Nhap vao cay nhi phan tim kiem cac so nguyen
    1. Tim kiem tren cay nhi phan
    2. Xuat cac node co 2 con (co ton tai cay con trai & phai)
    3. Xuat cac node co 1 con (chi ton tai 1 trong 2: cay con trai hoac cay con phai)
    4. Xuat cac node la (node khong ton tai cay con trai va cay con phai)
    5. Tim max - min
    6. Xoa
*/

#include <iostream>
using namespace std;

// Khai bao cau truc 1 node
struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE *TREE;

// Khoi tao BST
void initBST(TREE &t)
{
    t = NULL;
}

// them node vao cay
void inputNode(TREE &t, int x)
{
    if (t == NULL)
    {
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else
    {
        if (x < t->data)
        {
            inputNode(t->pLeft, x);
        }
        else if (x > t->data)
        {
            inputNode(t->pRight, x);
        }
    }
}

// duyet cay - in ra man hinh
void outputNLR(TREE t)
{
    if (t != NULL)
    {
        cout << t->data << "  ";
        outputNLR(t->pLeft);
        outputNLR(t->pRight);
    }
}

// tim node trong cay: neu ton tai -> tra ve node || khong ton tai -> tra ve NULL
NODE *TimKiem(TREE t, int x)
{
    // neu cay rong
    if (t == NULL)
    {
        return NULL;
    }
    else
    {
        // x < root: duyet (de quy) sang trai de tim
        if (x < t->data)
        {
            TimKiem(t->pLeft, x);
        }
        else if (x > t->data) // duyet de quy sang phai
        {
            TimKiem(t->pRight, x);
        }
        else // <=> t->data == x
        {
            return t; // tra ve node can tim
        }
    }
    return 0;
}

// xuat cac node co 2 con
void node2Child(TREE t)
{
    if (t != NULL)
    {
        if (t->pLeft != NULL && t->pRight != NULL)
        {
            cout << t->data << "  ";
        }

        node2Child(t->pLeft);  // duyet sang cay con trai cua lop hien tai
        node2Child(t->pRight); // duyet sang cay con phai cua lop hien tai
    }
}

// xuat cac node co 1 con
void node1Child(TREE t)
{
    if (t != NULL)
    {
        if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
        {
            cout << t->data << "  ";
        }

        node1Child(t->pLeft);  // duyet sang cay con trai cua lop hien tai
        node1Child(t->pRight); // duyet sang cay con phai cua lop hien tai
    }
}

// xuat cac node la
void node0Child(TREE t)
{
    if (t != NULL)
    {
        if (t->pLeft == NULL && t->pRight == NULL)
        {
            cout << t->data << "  ";
        }
        node0Child(t->pLeft);  // duyet sang cay con trai cua lop hien tai
        node0Child(t->pRight); // duyet sang cay con phai cua lop hien tai
    }
}

//******** CACH 1 ********
/*
// tim MAX in BST
int MAX = INT_MIN; // gan cho MAX = gia tri nho nhat cua kieu integer
void searchMax(TREE t)
{
    if (t != NULL)
    {
        if (MAX < t->data)
        {
            MAX = t->data;
        }
        searchMax(t->pLeft);
        searchMax(t->pRight);
    }
}

// tim MIN in BST
int MIN = INT_MAX; // gan cho MIN = gia tri lon nhat cua kieu integer
void searchMin(TREE t)
{
    if (t != NULL)
    {
        if (MIN > t->data)
        {
            MIN = t->data;
        }
        searchMin(t->pLeft);
        searchMin(t->pRight);
    }
}

*/

//******** CACH 2 ********
/*
int searchMax(TREE t)
{
    // root khong ton tai cay con trai va cay con phai
    if (t->pLeft == NULL && t->pRight == NULL)
    {
        return t->data;
    }
    int max = t->data; // gan max = root

    // neu cay con ton tai cay con trai (de quy sang trai)
    if (t->pLeft != NULL)
    {
        int left = searchMax(t->pLeft); // left : bien se chua gia tri cua cai node ngoai cung nhat ben trai cua node cha
        if (max < left)
        {
            max = left;
        }
    }
    // neu cay con ton tai cay con phai (de quy sang phai)
    if (t->pRight != NULL)
    {
        int right = searchMax(t->pRight); // left la bien se chua gia tri cua cai node ngoai cung nhat ben trai cua node cha
        if (max < right)
        {
            max = right;
        }
    }
    return max; // tra ve gia tri lon nhat cua cay nhi phan tim kiem
}

*/

//******** CACH 3 ********
int searchMax(TREE t)
{
    // root khong ton tai cay con phai
    if (t->pRight == NULL)
    {
        return t->data;
    }
    return searchMax(t->pRight);
}

int searchMin(TREE t)
{
    // root khong ton tai cay con trai
    if (t->pLeft == NULL)
    {
        return t->data;
    }
    return searchMin(t->pLeft);
}

// menu
void menu(TREE &t)
{
    while (true)
    {
        system("cls");
        cout << "\n\n\t ============================ MENU ============================\n"
             << endl;
        cout << "\t\t1. Them phan tu vao BST." << endl;
        cout << "\t\t2. Xuat BST." << endl;
        cout << "\t\t3. Tim kiem phan tu trong BST." << endl;
        cout << "\t\t4. Xuat cac node co 2 con trong BST." << endl;
        cout << "\t\t5. Xuat cac node co 1 con trong BST." << endl;
        cout << "\t\t6. Xuat cac node la trong BST." << endl;
        cout << "\t\t7. Xuat node co gia tri Max trong BST." << endl;
        cout << "\t\t8. Xuat node co gia tri Min trong BST." << endl;
        cout << "\t\t0. Thoat." << endl;
        cout << "\n\t ============================= END =============================" << endl;

        int select;
        cout << "\n\tNhap lua chon cua ban: ";
        cin >> select;

        if (select == 0)
        {
            cout << "\n\tDone. See you again!\n"
                 << endl;
            break;
        }
        else if (select == 1)
        {
            int x;
            cout << "\n\tNhap so nguyen x = ";
            cin >> x;
            inputNode(t, x);
            cout << endl;
        }
        else if (select == 2)
        {
            cout << "\n\tDanh sach phan tu trong cay nhi phan la: ";
            outputNLR(t);
            cout << endl;
            system("pause");
        }
        else if (select == 3)
        {
            int x;
            cout << "\nNhap phan tu can tim kiem: ";
            cin >> x;
            NODE *p = TimKiem(t, x);
            if (p == NULL)
            {
                cout << "\nPhan tu " << x << " khong ton tai trong cay" << endl;
            }
            else
            {
                cout << "\nPhan tu " << x << " co ton tai trong cay" << endl;
            }
            system("pause");
        }
        else if (select == 4)
        {
            cout << "\n\tCac node co 2 con trong BST: ";
            node2Child(t);
            cout << endl;
            system("pause");
        }
        else if (select == 5)
        {
            cout << "\n\tCac node co 1 con trong BST: ";
            node1Child(t);
            cout << endl;
            system("pause");
        }
        else if (select == 6)
        {
            cout << "\n\tCac node la trong BST: ";
            node0Child(t);
            cout << endl;
            system("pause");
        }
        else if (select == 7)
        {
            /* ******* CACH 1 ******* 
            searchMax(t);
            cout << "\n\tMax(node) = " << MAX << endl;
            */

            /* ******* CACH 2 ******* */
            cout << "\n\tMax(node) = " << searchMax(t) << endl;
            system("pause");
        }
        else if (select == 8)
        {
            /* ******* CACH 1 ******* 
            searchMin(t);
            cout << "\n\tMin(node) = " << MIN << endl;
            */

            /* ******* CACH 2 ******* */
            cout << "\n\tMin(node) = " << searchMin(t) << endl;
            system("pause");
        }
        else
        {
            cout << "\n\tGia tri nhap khong hop le. Vui long nhap lai!\n"
                 << endl;
            system("pause");
        }
    }
}

int main()
{
    TREE t;
    initBST(t);
    menu(t);

    system("pause");
    return 0;
}