/*
* Đệ quy: là một hàm được định nghĩa dựa trên chính nó.
* Yêu cầu: Viết hàm đệ quy tính n! 
* Tư tưởng:
        0! = 1
        1! = 1
        2! = 2x1!
        3! = 3x2!
        4! = 4x3!
        5! = 5x4!
        .........
*/

#include <iostream>
using namespace std;

int giaithua(int n)
{
    if (n == 0) // trường hợp suy biến (trường hợp cơ bản)
    {
        return 1;
    }
    else // trường hợp tổng quát
        return n * giaithua(n - 1);
}

int main()
{
    cout << giaithua(5);
    return 0;
}
