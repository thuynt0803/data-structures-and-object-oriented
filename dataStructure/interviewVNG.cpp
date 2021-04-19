/***
 * Mình đã được giao một bài tập nhỏ trong buổi phỏng vấn đầu tiên tại VNG...
 * Cảm xúc khá hỗn độn tại thời điểm này, nhưng mà thôi mình sẽ không chia sẻ ở đâyyy... thử làm lại đã nha!!!
 * 
 * Đề bài:
 *      Cho mảng 10 số nguyên gồm các số từ 1 đến 10, các số không được sắp xếp theo thứ tự. Hiện tại trong mảng đã tồn tại 9 số.
 *      Yêu cầu: Tìm 1 số còn thiếu trong mảng đó.
 * 
 * Ý tưởng:
 *      1. Sử dụng hàm băm (hash function) - bảng băm (hash table). Mình chưa từng thử kỹ thuật này...
 *      2. Sắp xếp mảng tăng dần, sử dụng vòng lặp để kiểm tra giá trị a[j] = a[i] + 1.
 *      3. Tính tổng các giá trị trong mảng (sum1); tính tổng các số từ 1 đến 10 (sum2): x cần tìm = sum2 - sum1
 * 
 * ==> Trong bài này mình sẽ sử dụng cách 3 để tìm x.
 **/

#include <iostream>
using namespace std;
#define N 10

void inputArr(int a[]);
void outputArr(int a[]);
int sumArr(int a[]);
int sum(int n);

int main()
{
    int a[N], x;
    int n = 10;
    inputArr(a);
    outputArr(a);

    cout << "\n==> Gia tri x con thieu la: " << sum(n) - sumArr(a) << endl;
    return 0;
}

void inputArr(int a[])
{
    cout << "\nNOTE: Nhap 9 so nguyen trong khoang [1 ; 10], moi so chi duoc nhap 1 lan duy nhat." << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "\ta[" << i << "] = ";
        cin >> a[i];

        // viet ham xu ly nhap gia tri trung (xu ly sau)
    }
}

void outputArr(int a[])
{
    int tg;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
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

    cout << "\nDay so sau khi sap xep tang dan la: ";
    for (int i = 0; i < 9; i++)
    {
        cout << "  " << a[i];
    }
}

int sumArr(int a[])
{
    int sumA = 0;
    for (int i = 0; i < 9; i++)
    {
        sumA += a[i];
    }
    return sumA;
}

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return sum(n - 1) + n;
}