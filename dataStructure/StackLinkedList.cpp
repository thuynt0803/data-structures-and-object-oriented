
/* NHẬP DANH SÁCH STACK CHỨA CÁC SỐ NGUYÊN, SAU ĐÓ XUẤT RA MÀN HÌNH CÁC GIÁ TRỊ SỐ NGUYÊN ĐÓ */

#include <iostream>
using namespace std;

// Khai báo cầu trúc của 1 node

struct node
{
    int data;           // stack đang chứa các số nguyên
    struct node *pNext; // con trỏ liên kết giữa các node với nhau
};
typedef struct node NODE;

struct stack
{
    NODE *pTop; // dùng con trỏ đầu để quản lý stack
};
typedef struct stack STACK;

// hàm khởi tạo stack
void initStack(STACK &s)
{
    s.pTop = NULL;
}

// khởi tạo 1 node
NODE *initNode(int x)
{
    NODE *p = new NODE();
    if (p == NULL)
    {
        cout << "\n==> Khong du bo nho cap phat." << endl;
        return NULL;
    }
    p->data = x; // thêm giá trị của biến x vào trong data của node
    p->pNext = NULL;
    return p;
}

// CHECK STACK EMPTY
bool IsEmpty(STACK &s)
{
    // nếu danh sách rỗng
    if (s.pTop == NULL)
    {
        return true;
    }
    return false; // danh sách có phần tử
}

// Thêm 1 đối tượng vào đầu stack và hủy nó đi - LIFO
bool Push(STACK &s, NODE *p)
{
    if (p == NULL)
    {
        return false;
    }

    // nếu danh sách rỗng
    if (IsEmpty(s) == true)
    {
        s.pTop = p; // node p chính là node đầu stack
    }
    else // danh sách đã có phần tử
    {
        p->pNext = s.pTop; //cho con trỏ của node p trỏ đến node đầu danh sách <=> tạo liên kết
        s.pTop = p;        // cập nhật lại node đầu
    }
    return true;
}

// Lấy phần tử đầu stack và hủy nó đi - LIFO
bool Pop(STACK &s, int &x) // x chính là giá trị cần lấy trong node
{
    if (IsEmpty(s) == true)
    {
        return false;
    }
    else
    {
        NODE *p = s.pTop;       // node p là node thay thế để xóa nó đi
        x = p->data;            // gán giá trị của node đầu stack vào biến x
        s.pTop = s.pTop->pNext; // cập nhật node đầu stack là node tiếp theo
        delete p;               // xóa node đầu stack vừa lấy
    }
    return true; // lấy phần tử đầu stack thành công
}

// Xem thông tin của phần tử đầu stack và không hủy nó đi
bool Top(STACK &s, int &x) // x chính là giá trị cần lấy ra để xem
{
    if (IsEmpty(s) == true)
    {
        return false;
    }
    x = s.pTop->data; // lấy giá trị của phần tử đầu stack ra để xem
    return true;      // lấy phần tử đầu stack thành công
}

// hàm xuất danh sách stack
void outputStack(STACK &s)
{
    while (IsEmpty(s) == false)
    {
        int x;
        Pop(s, x);
        cout << x << "   ";
    }
    cout << endl;
    if (IsEmpty(s) == true)
    {
        cout << "==> Danh sach dang rong!" << endl;
    }
    else
        cout << "==> Danh sach van ton tai phan tu!" << endl;
}

// hàm nhập danh sách các số nguyên trong stack
void inputStack(STACK &s)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=========================== MENU ===========================" << endl;
        cout << "\n\t1. Them phan tu vao stack - Push";
        cout << "\n\t2. Xuat danh sach stack ra man hinh - Pop";
        cout << "\n\t3. Xem thong tin phan tu dau stack - Top";
        cout << "\n\t0. Ket thuc";
        cout << "\n\n\t\t=========================== END ===========================" << endl;

        cout << "\nNhap lua chon cua ban? - ";
        cin >> luachon;
        if (luachon == 1)
        {
            int x;
            cout << "\nNhap phan tu can them: x = ";
            cin >> x;
            NODE *p = initNode(x);
            Push(s, p);
        }
        else if (luachon == 2)
        {
            cout << "\nDanh sach so nguyen trong stack la: ";
            outputStack(s);
            system("pause");
        }
        else if (luachon == 3)
        {
            int x;
            Top(s, x);
            cout << "\nPhan tu dau stack la: " << x << endl;
            system("pause");
        }
        else
            break;
    }
}

int main()
{
    STACK s;
    initStack(s);
    inputStack(s);

    system("pause");
    return 0;
}