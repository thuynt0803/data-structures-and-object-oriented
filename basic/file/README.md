# (>.<)

> Có quá nhiều rắc rối xảy ra khi tôi làm việc với tập tin chứa ký tự unicode trên nền tảng windows, tôi đã nghĩ mình sẽ bỏ cuộc ... aaa ...
> Mặc dù biết phần này khá quan trọng mà thôi để làm sau vậy!!! -.-

# Tổng quát
## Thư viện:

> - ifstream : hỗ trợ đọc gữ liệu từ file (bản chất là 1 class)
> - ofstream : hỗ trợ ghi dữ liệu vào file (bản chất là 1 class)
> - fstream : hỗ trợ bao gồm cả đọc + ghi file

## Các chế độ mở tệp tin (file):

> - ios::in - mở file để đọc
> - ios::out - mở file có sẵn để ghi
> - ios::app - mở file có sẵn để thêm dữ liệu vào cuối tệp
> - ios::ate - mở file và đặt con trỏ file vào cuối tệp
> - ios::trunc - nếu file đã có sẵn thì dữ liệu của nó sẽ bị mất
> - ios::nocreate - mở file, file này bắt buộc phải tồn tại
> - ios::binary - mở file ở chế độ nhị phân. Khi file được mở ra ở chế độ này thì dữ liệu sẽ dược đọc hay ghi từ 1 định dạng nguyên thủy nhị phân
> - ios::text: mở file ở chế độ văn bản
