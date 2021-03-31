
/* NHẬP DANH SÁCH QUEUE CHỨA CÁC SỐ NGUYÊN, SAU ĐÓ XUẤT RA MÀN HÌNH CÁC GIÁ TRỊ SỐ NGUYÊN ĐÓ */

#include <iostream>
using namespace std;

// Khai báo cầu trúc của 1 node trong queue

struct node
{
    int data;           // queue đang chứa các số nguyên
    struct node *pNext; // con trỏ liên kết giữa các node với nhau
};
typedef struct node NODE;

struct queue
{
    NODE *pHead; // con trỏ đầu
    NODE *pTail; // con trỏ cuối
};
typedef struct queue QUEUE;

// hàm khởi tạo queue
void initQueue(QUEUE &q)
{
    q.pHead = NULL;
    q.pTail = NULL;
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

// CHECK QUEUE EMPTY
bool IsEmpty(QUEUE q)
{
    // nếu danh sách rỗng
    if (q.pHead == NULL)
    {
        return true;
    }
    return false; // danh sách có phần tử
}

// Thêm 1 phần tử vào cuối QUEUE - FIFO
bool Push(QUEUE &q, NODE *p)
{
    if (p == NULL)
    {
        return false;
    }

    // nếu danh sách rỗng
    if (IsEmpty(q) == true)
    {
        q.pHead = q.pTail = p; // node p chính là node đầu và node cuối queue
    }
    else // danh sách đã có phần tử
    {
        q.pTail->pNext = p; // liên kết con trỏ cuối của danh sách với phần tử p cần thêm vào
        q.pTail = p;        // cập nhật lại con trỏ cuối là node p
    }
    return true;
}

// Lấy phần tử đầu queue và hủy nó đi - FIFO
bool Pop(QUEUE &q, int &x) // x chính là giá trị cần lấy trong node
{
    if (IsEmpty(q) == true)
    {
        return false;
    }
    else
    {
        NODE *p = q.pHead;        // node p là node thay thế để xóa nó đi
        x = p->data;              // gán giá trị của node đầu queue vào biến x
        q.pHead = q.pHead->pNext; // cập nhật node đầu queue là node tiếp theo
        delete p;                 // xóa node đầu queue vừa lấy
    }
    return true; // lấy phần tử đầu queue thành công
}

// Xem thông tin của phần tử đầu queue và không hủy nó đi
bool Top(QUEUE &q, int &x) // x chính là giá trị cần lấy ra để xem
{
    if (IsEmpty(q) == true)
    {
        return false;
    }
    x = q.pHead->data; // lấy giá trị của phần tử đầu stack ra để xem
    return true;       // lấy phần tử đầu stack thành công
}

// hàm xuất danh sách queue
void outputQueue(QUEUE q)
{
    while (IsEmpty(q) == false)
    {
        int x;
        Pop(q, x);
        cout << x << "   ";
    }
    cout << endl;
    if (IsEmpty(q) == true)
    {
        cout << "==> Danh sach dang rong!" << endl;
    }
    else
        cout << "==> Danh sach van ton tai phan tu!" << endl;
}

// hàm nhập danh sách các số nguyên trong queue
void inputQueue(QUEUE &q)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=========================== MENU ===========================" << endl;
        cout << "\n\t1. Them phan tu vao queue - Push";
        cout << "\n\t2. Xuat danh sach queue ra man hinh - Pop";
        cout << "\n\t3. Xem thong tin phan tu dau queue - Top";
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
            Push(q, p);
        }
        else if (luachon == 2)
        {
            cout << "\nDanh sach so nguyen trong queue la: ";
            outputQueue(q);
            system("pause");
        }
        else if (luachon == 3)
        {
            int x;
            Top(q, x);
            cout << "\nPhan tu dau queue la: " << x << endl;
            system("pause");
        }
        else
        {
            break;
        }
    }
}

int main()
{
    QUEUE q;
    initQueue(q);
    inputQueue(q);

    system("pause");
    return 0;
}