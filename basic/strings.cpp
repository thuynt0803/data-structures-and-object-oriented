/*
    Mảng kí tự trong C++:
        - Luôn kết thúc bởi kí tự null '\0'
        - Lấy độ dài thực tế của mảng kí tự, dùng hàm: strlen()
*/

#include <iostream>
using namespace std;

int main()
{
    int age;
    char fullname[200];
    cout << "Enter your age: ";
    cin >> age;
    cin.ignore(); // xóa kí tự thừa (enter)
    cout << "Enter your name: ";
    cin.getline(fullname, 199); // đọc 1 chuỗi kí tự chứa cả dấu cách:

    cout << "\n\"Hello, I am " << fullname << ", I am " << age << " year olds.\"" << endl;
    size_t length = strlen(fullname); // độ dài của chuỗi
    cout << "\nDo dai cua chuoi fullname la: " << length << endl;

    return 0;
}