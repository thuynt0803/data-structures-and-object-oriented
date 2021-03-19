/*
    - Sử dụng thư viện 'fstream' để làm việc với file
    - ifstream : hỗ trợ đọc gữ liệu từ file (bản chất là 1 class)
    - ofstream : hỗ trợ ghi dữ liệu vào file (bản chất là 1 class)
    - Các chế độ mở tệp tin (file):
        ios::in - mở file để đọc
        ios::out - mở file có sẵn để ghi
        ios::app - mở file có sẵn để thêm dữ liệu vào cuối tệp
        ios::ate - mở file và đặt con trỏ file vào cuối tệp
        ios::trunc  - nếu file đã có sẵn thì dữ liệu của nó sẽ bị mất
        ios::nocreate - mở file, file này bắt buộc phải tồn tại
        ios::binary - mở file ở chế độ nhị phân. Khi file được mở ra ở chế độ này thì dữ liệu sẽ dược đọc hay ghi từ 1 định dạng nguyên thủy nhị phân
        ios::text: mở file ở chế độ văn bản
    
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //====================== ĐỌC FILE ======================
    //B1: Khai báo biến để đọc file
    //Cú pháp: ifstream <tên biến file>;
    ifstream fileIn;

    //B2: Mở file cần đọc dữ liệu
    //Cú pháp: open(<tên đường dẫn đến file cần mở - để đọc>,<chế độ làm việc với file>)
    //ios_base::in - mở file để đọc; out - ghi
    fileIn.open("D:\\learning-project\\algorithms-C++\\basic\\fileDemo.txt", ios_base::in);
    if (fileIn.fail() == true) // kiểm tra sự tồn tại của file: true == không tồn tại, false == tồn tại
    {
        cout << "\nFile khong ton tai.";
        return 0; // kết thúc chương trình
    }

    //B3: Xử lý file
    int x, y;
    // cin >> x;
    fileIn >> x; // đọc dữ liệu từ file
    // cin >> y;
    fileIn >> y;

    cout << "\nTong x + y = " << x + y;

    //B4: Đóng file
    fileIn.close(); // Đóng file lại sau khi đã xử lý

    //====================== GHI FILE ======================
    ofstream fileOut;
    fileOut.open("D:\\learning-project\\algorithms-C++\\basic\\fileDemo.txt", ios_base::out);
    fileOut << x + y; // Lấy x + y rồi ghi vào file

    fileOut.close();

    return 0;
}