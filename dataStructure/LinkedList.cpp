/*    Bài toán: Nhập danh sách liên kết đơn các số nguyên. Tìm giá trị lớn nhất trong danh sách   */

#include <iostream>
using namespace std;

/* ======================== KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN ============================== */

//     1. Khai báo cấu trúc của 1 node
struct node
{
    int data;           // data chứa trong 1 cái node
    struct node *pNext; // con trỏ dùng để liên kết giữa các node với nhau
};
typedef struct node NODE; // thay thế struct node thành NODE

//    2. Khai báo cấu trúc của linked list
struct list
{
    NODE *pHead; // node quản lý đầu danh sách
    NODE *pTail; // node quản lý cuối danh sách
};
typedef struct list LIST; // thay thế struct list thành LIST

/* ======================== KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN ============================== */
void initList(LIST &l)
{
    // cho hai node trỏ đến NULL vì dslk đơn chưa có phần tử
    l.pHead = NULL;
    l.pTail = NULL;
}

// Hàm khởi tạo 1 cái node
NODE *initNODE(int x)
{
    NODE *p = new NODE; // Cấp phát vùng nhớ cho NODE p
    if (p == NULL)
    {
        cout << "\nKhong du bo nho de cap phat!" << endl;
        return NULL;
    }

    p->data = x;     // truyền giá trị x vào cho data
    p->pNext = NULL; // đầu tiên khai báo node thì node đó chưa có liên kết đến node nào hết ==> con trỏ của nó sẽ trỏ đến NULL
    return p;        // trả về NODE p vừa khởi tạo
}

// Hàm thêm node p vào đầu danh sách liên kết
void inputFirst(LIST &l, NODE *p)
{
    if (l.pHead == NULL) // Danh sách đang rỗng
    {
        l.pHead = l.pTail = p; // node đầu là node cuối và là p
    }
    else // Danh sách không rỗng
    {
        p->pNext = l.pHead; // cho con trỏ của node cần thêm là node p liên kết đến node đầu - pHead
        l.pHead = p;        // cập nhật lại pHead chính là node p
    }
}

// Hàm thêm node p vào cuối danh sách liên kết đơn
void inputLast(LIST &l, NODE *p)
{
    if (l.pHead == NULL) // Danh sách đang rỗng
    {
        l.pHead = l.pTail = p; // node đầu là node cuối và là p
    }
    else // Danh sách không rỗng
    {
        l.pTail->pNext = p; // cho con trỏ của pTail liên kết với node p
        l.pTail = p;        // cập nhật lại p là node pTail
    }
}

// Hàm thêm node p vào sau node q (node đã tồn tại trong dslk)
void inputAfterAnything(LIST &l, NODE *p)
{
    int x;
    cout << "\nNhap node q = ";
    cin >> x;

    NODE *q = initNODE(x);

    // Nếu danh sách chỉ có 1 phần tử và phần tử đó cũng chính là node q ==> bài toán trở thành kỹ thuật thêm vào cuối danh sách
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        inputLast(l, p);
    }
    else
    {
        // ================ DANH SÁCH TỒN TẠI 2 NODE Q TRỞ LÊN ===================

        // Duyệt từ đầu danh sách đến cuối danh sách để tìm node q
        for (NODE *k = l.pHead; k != NULL; k = k->pNext)
        {
            // nếu node q có tồn tại thì
            if (q->data == k->data)
            {
                NODE *h = initNODE(p->data); // khởi tạo một node h mới để thêm vào sau node q
                NODE *g = k->pNext;          // cho node g trỏ đến node nằm sau node q
                h->pNext = g;                // Bước 1: Tạo mối liên kết từ node h đến node g <=> cũng chính là tạo mối liên kết từ node h đến node nằm sau node q
                k->pNext = h;                // Tạo mối liên kết từ node q đến node h <=> chính là node k đến node h
            }
        }
    }
}

// Hàm thêm node p vào trước node q (node đã tồn tại trong dslk)
void inputFirstAnything(LIST &l, NODE *p)
{
    int x;
    cout << "\nNhap node q = ";
    cin >> x;

    NODE *q = initNODE(x);

    // Nếu danh sách chỉ tồn tại duy nhất 1 phần tử và phần tử đó cũng chính là node q ==> bài toán trở thành kỹ thuật thêm vào đầu danh sách
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        inputFirst(l, p);
    }
    else
    {

        // ================ DANH SÁCH CHỈ TỒN TẠI 1 NODE Q ===================

        // NODE *g = new NODE; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
        // // Duyệt từ đầu danh sách đến cuối danh sách để tìm node q
        // for (NODE *k = l.pHead; k != NULL; k = k->pNext)
        // {
        //     // nếu node q có tồn tại trong danh sách thì bắt đầu thêm node p vào sau node q
        //     if (q->data == k->data)
        //     {
        //         // thực hiện bài toán thêm node p vào sau node g <=> thêm node p vào trước node q
        //         p->pNext = k; // B1: Cho node p trỏ (liên kết) đến node k <=> cho node p trỏ đến node q
        //         g->pNext = p; // B2: Cho node g trỏ đến node p
        //     }
        //     g = k; // giữ liên kết với node nằm trước node q trong danh sách
        // }

        // ================ DANH SÁCH TỒN TẠI 2 NODE Q TRỞ LÊN ===================
        NODE *g = new NODE; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
        // Duyệt từ đầu danh sách đến cuối danh sách để tìm node q
        for (NODE *k = l.pHead; k != NULL; k = k->pNext)
        {
            // nếu node q có tồn tại trong danh sách thì bắt đầu thêm node p vào sau node q
            if (q->data == k->data)
            {
                NODE *h = initNODE(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
                // thực hiện bài toán thêm node p vào sau node g <=> thêm node p vào trước node q
                h->pNext = k; // B1: Cho node h trỏ (liên kết) đến node k <=> cho node h trỏ đến node q
                g->pNext = h; // B2: Cho node g trỏ đến node p
            }
            g = k; // giữ liên kết với node nằm trước node q trong danh sách
        }
    }
}

// Hàm xóa node đầu danh sách
void deleteFirst(LIST &l)
{
    // Neu danh sach rong
    if (l.pHead == NULL)
    {
        return;
    }
    NODE *p = l.pHead;        // node p la node se duoc xoa
    l.pHead = l.pHead->pNext; // cap nhat lai l.pHead la phan tu ke tiep
    delete p;
}

// Hàm xóa node cuối danh sách
void deleteLast(LIST &l)
{
    // Neu danh sach rong
    if (l.pHead == NULL)
    {
        return;
    }

    // trường hợp danh sách có 1 phần tử
    if (l.pHead->pNext == NULL)
    {
        deleteFirst(l);
        return;
    }

    // duyệt từ đầu danh sách đến node kế cuối
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        // phát hiện thằng kế cuối
        if (k->pNext == l.pTail)
        {
            delete l.pTail;  // xo di phan tu cuoi
            k->pNext = NULL; // cho con tro cua node ke cuoi tro den vung nho null
            l.pTail = k;     // Cap nhat lai l.pTail
            return;
        }
    }
}

// Hàm xóa 1 node năm sau node q trong danh sách
void deleteLastAnything(LIST &l, NODE *q)
{
    // kiem tra danh sach rong
    if (l.pHead == NULL)
    {
        return;
    }

    // duyet danh sach tu dau den cuoi de tim node q
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        // phat hien node q
        if (k->data == q->data)
        {
            NODE *g = k->pNext;  // node g la node nam sau node k <=> node duoc yeu cau xoa
            k->pNext = g->pNext; // cap nhat moi lien ket giua node k (node q) voi node sau node g
            delete g;            // xoa node nam sau node q
        }
    }
}

// Hàm xóa 1 node có khóa k (so nguyen x) bất kỳ
void deleteAnyX(LIST &l, int x)
{
    // kiem tra danh sach rong
    if (l.pHead == NULL)
    {
        return;
    }
    // neu node can xoa nam dau danh sach
    if (l.pHead->data == x)
    {
        deleteFirst(l);
        return;
    }
    // neu node can xoa nam cuoi danh sach
    if (l.pTail->data == x)
    {
        deleteLast(l);
        return;
    }

    NODE *g = new NODE; // node g la node tro den node nam truoc node can xoa (x)
    // duyet danh sach de tim x
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data == x)
        {
            g->pNext = k->pNext; // cap nhat moi lien ket giua node k voi node sau node k
            delete k;            // xoa node nam sau node k
            return;
        }
        g = k; // cho node g tro den node k
    }
}

// Hàm tìm giá trị lớn nhất trong danh sách
int searchMax(LIST l)
{
    int max = l.pHead->data; // giả sử node đầu là node có giá trị lớn nhất
    // bắt đầu duyệt từ node thứ 2 để kiểm tra
    for (NODE *k = l.pHead->pNext; k != NULL; k = k->pNext)
    {
        if (max < k->data)
        {
            max = k->data; // cập nhật lại giá trị max
        }
    }
    return max;
}

// Xuất danh sách
void outputList(LIST l)
{
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << "\t" << k->data << "\t";
    }
}

void menu(LIST &l)
{
    int luachon;
    while (true)
    {       
        system("cls");
        cout << "\n\n\t\t==================== MENU ====================" << endl;
        cout << "\n\t1. Them node vao danh sach" << endl;
        cout << "\t2. Xuat danh sach lien ket don" << endl;
        cout << "\t3. Them node p vao sau node q trong danh sach" << endl;
        cout << "\t4. Them node p vao truoc node q trong danh sach" << endl;
        cout << "\t5. Tim max trong danh sach da nhap" << endl;
        cout << "\t6. Xoa node dau danh sach" << endl;
        cout << "\t7. Xoa node cuoi danh sach" << endl;
        cout << "\t8. Xoa 1 node sau node q danh sach" << endl;
        cout << "\t9. Xoa node co khoa k bat ky" << endl;

        cout << "\t0. Thoat" << endl;
        cout << "\n\t\t==================== END ====================" << endl;

        cout << "\nNhap lua chon cua ban: ";
        cin >> luachon;

        if (luachon < 0 || luachon > 9)
        {
            cout << "\nLua chon khong hop le, kiem tra lai!" << endl;
            system("pause");
        }
        else if (luachon == 1)
        {
            int x;
            cout << "\n\tx = ";
            cin >> x;
            NODE *p = initNODE(x); // khởi tạo 1 cái node
            inputLast(l, p);
        }
        else if (luachon == 2)
        {
            cout << "\n\n==> Danh sach duoc nhap la: ";
            outputList(l);
            cout << endl;
            system("pause");
        }
        else if (luachon == 3)
        {
            int x;
            cout << "\nNhap gia tri node p can them vao sau index: p = ";
            cin >> x;
            NODE *p = initNODE(x);
            inputAfterAnything(l, p); // Thêm node p vào sau node q trong danh sách l
        }
        else if (luachon == 4)
        {
            int x;
            cout << "\nNhap gia tri node p can them vao truoc q: p = ";
            cin >> x;
            NODE *p = initNODE(x);
            inputFirstAnything(l, p); // Thêm node p vào sau node q trong danh sách l
        }
        else if (luachon == 5)
        {
            cout << "\n==> So lon nhat trong danh sach la: " << searchMax(l) << endl;
            system("pause");
        }
        else if (luachon == 6)
        {
            deleteFirst(l);
            cout << "\n==> Da xoa phan tu dau danh sach" << endl;
            system("pause");
        }
        else if (luachon == 7)
        {
            deleteLast(l);
            cout << "\n==> Da xoa phan tu cuoi danh sach" << endl;
            system("pause");
        }
        else if (luachon == 8)
        {
            int x;
            cout << "\nNhap node q (node da ton tai trong danh sach): q = ";
            cin >> x;
            NODE *q = initNODE(x);
            deleteLastAnything(l, q);
        }
        else if (luachon == 9)
        {
            int x;
            cout << "\nNhap node can xoa: ";
            cin >> x;
            deleteAnyX(l, x);
        }
        else
            break;
    }
}

int main()
{
    LIST l;
    initList(l); // luôn luôn khởi tạo danh sách lk đơn trước khi thao tác với danh sách

    menu(l);
    system("pause");
    return 0;
}
