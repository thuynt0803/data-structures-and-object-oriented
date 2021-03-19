/*
    Yêu cầu:  Làm việc với mảng 1 chiều
*/

#include <iostream>
using namespace std;

#define N 50

void inputArr(int a[], int n)
{
    cout << "Enter the number range: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\ta[" << i << "] = ";
        cin >> a[i];
    }
}

void outputArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "  " << a[i];
    }
}

void increaseSortUp(int a[], int n) // SX tăng
{
    int tg;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Hoan vi 2 so a[i] va a[j]
            if (a[i] > a[j])
            {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
    cout << "\n\nSequence of numbers after ascending sorting: ";
    outputArr(a, n);
}

void decreaseSortUp(int a[], int n) // SX giảm
{
    int tg;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Hoan vi 2 so a[i] va a[j]
            if (a[i] < a[j])
            {
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
    cout << "\n\nSequence of numbers after descending sorting: ";
    outputArr(a, n);
}

int searchX(int a[], int n, int x) // Tìm kiếm sự tồn tại của X
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

// Truyền tham chiếu cho tham số n vì n bị thay đổi
void insertX(int a[], int &n, int vitrichen, int socanchen) // Chèn phần tử vào 1 vị trí bất kỳ trong mảng
{
    for (int i = n; i >= vitrichen; i--)
    {
        a[i] = a[i - 1];
    }
    a[vitrichen] = socanchen;
    n++;
}

void deleteX(int a[], int &n, int vitrixoa) // Xóa 1 phần tử ra khỏi mảng
{
    for (int i = vitrixoa; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}

void deleteEvenNumbers(int a[], int &n) // Xóa số chẵn tồn tại trong mảng
{
    for (int i = 0; i < n;)
    {
        if (a[i] % 2 == 0)
        {
            deleteX(a, n, i);
        }
        else
        {
            i++;
        }
    }
    /*
        Để i++ tại vòng lặp else vì sau khi gọi hàm deleteX, 
        vị trí của i được gán về vị trí ban đầu. 
        Tránh trường hợp lỗi khi trong mảng tồn tại các số chẵn liên tiếp nhau.
    */
}

int main()
{
    int n, a[N], x;
    int vtchen, socanchen;
    int vtxoa;
    do
    {
        cout << "\nEnter the number of elements: n = ";
        cin >> n;
        if (n > N)
        {
            cout << "Number of imported elements is too limited, please re-enter!" << endl;
        }
        cout << endl;
    } while (n >= N);

    inputArr(a, n);
    cout << "\nThe sequence of numbers is entered: ";
    outputArr(a, n);

    cout << "\n\nEnter X = ";
    cin >> x;
    if (searchX(a, n, x) == 1)
    {
        cout << "==> X is in array." << endl;
    }
    else
        cout << "==> X isn't in array." << endl;

    cout << "\nEnter the location to insert: ";
    cin >> vtchen;
    cout << "Enter the number to be inserted: ";
    cin >> socanchen;
    insertX(a, n, vtchen, socanchen);
    cout << "Current number range: ";
    outputArr(a, n);

    cout << "\n\nEnter the location to delete: ";
    cin >> vtxoa;
    deleteX(a, n, vtxoa);
    cout << "Current number range: ";
    outputArr(a, n);

    cout << "\n\nDelete even numbers from the array: ";
    deleteEvenNumbers(a, n);
    outputArr(a, n);

    increaseSortUp(a, n);
    decreaseSortUp(a, n);
    return 0;
}