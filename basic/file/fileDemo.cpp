#include <iostream>
#include <fstream>
#include <string>
#include <codecvt> //Chuyển đổi giữa các mã hóa ký tự, bao gồm UTF-8, UTF-16, UTF-32

using namespace std;

int main()
{

    string line;
    // khởi tạo biến file "myfile", làm việc với file thay thế cin, cout
    fstream myfile;

    /*
    Sử dụng hàm open(filename, mode) để mở file, trong đó:
        - filename: là địa chỉ file được chọn
        - mode: là tham số tùy chọn để làm việc với file. Có thể kết hợp nhiều mode bằng cách sử dụng '|'
                Trong trường hợp không khai báo mode khi mở file, tham số mode mặc định sẽ được tự động giả định
                tương ứng với thư viện được sử dụng:
                    ofstream -> ios::out
                    ifstream ->	ios::in
                    fstream	 -> ios::in | ios::out
    */
    myfile.open(".\\basic\\fileDemo.txt", ios::in);

    /*
    Sử dụng hàm is_open() để kiểm tra xem file được mở thành công hay không.
    Hàm trả về giá trị kiểu bool: true = liên kết file thành công; false = liên kết file thất bại
    */
    if (myfile.is_open() == true)
    {
        cout << "File exist." << endl
             << endl;
        /*
        Tạo vòng lặp while để đọc dữ liệu trong file theo dòng và in nội dung của file lên màn hình, sử dụng getline().
        */
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
    }
    else
        cout << "Unable to open file." << endl;

    myfile.close();

    return 0;
}