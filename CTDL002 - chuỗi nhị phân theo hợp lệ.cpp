#include <iostream>
#include <string>

using namespace std;

void generateAllStrings(string& s, int index)
{
    if (index == s.size()) // Đã duyệt hết chuỗi
    {
        cout << s << endl; // In kết quả
        return;
    }

    if (s[index] == '?') // Nếu gặp ký tự '?' thì thử đặt '0' hoặc '1'
    {
        s[index] = '0';
        generateAllStrings(s, index + 1); // Gọi đệ quy
        s[index] = '1';
        generateAllStrings(s, index + 1); // Gọi đệ quy
        s[index] = '?'; // Đặt lại giá trị ban đầu để duyệt tiếp
    }
    else // Nếu không phải ký tự '?' thì tiếp tục duyệt tiếp
    {
        generateAllStrings(s, index + 1); // Gọi đệ quy
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        generateAllStrings(s, 0);
    }

    return 0;
}