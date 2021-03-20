/*
    Số armstrong là số mà từng chữ số trong số đó lũy thừa với số chữ số của nó bằng chính nó.
        ==> abcd... = a^n + b^n + c^n + d^n + ...
    Ý tưởng: 
        1. Tính tổng số chữ số
        2. Tính tổng các lũy thừa: Cơ số là các chữ số, số mũ là số lượng chữ số
        3. So sánh
*/

#include <iostream>
#include <math.h>
using namespace std;

int countDigit(int n) // Dem so chu so
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}

bool isAmstrong(int n)
{
    int numDigit = countDigit(n);
    int sum = 0, tmp = n, last;
    while (tmp > 0)
    {
        last = tmp % 10;            // Lay chu so cuoi cung
        tmp /= 10;                  // Bo chu so cuoi cung
        sum += pow(last, numDigit); //Luy thua tung chu so voi mu la so luong chu so
    }
    if (sum == n)
        return true;
    return false;
}

int main()
{
    int n;
    char ch;
    do
    {
        cout << "\nEnter a positive integer: ";
        cin >> n;

        if (n < 0)
        {
            cout << "\t==> " << n << " is not a positive integer. Invalid." << endl;
        }
        else
        {
            cout << "Check an amstrong number:" << endl;
            if (isAmstrong(n) == true)
            {
                cout << "\t==> " << n << " is an amstrong number." << endl;
            }
            else
            {
                cout << "\t==> " << n << " is not an amstrong number." << endl;
            }
        }

        cout << "Work with another number? (Y/N) - ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}