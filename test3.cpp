/* Bài 3: Tìm vị trí số cần xóa để được số nhỏ nhất
Input:
- s: Chuỗi số nguyên

Output:
- Vị trí số cần xóa
- Chuỗi số nhỏ nhất

Algorithm:
1. Tìm vị trí số lớn nhất để xóa (từ trái sang phải) (Với số đứng trước mà lớn hơn số đứng sau thì khi xoá vị trí hiện tại sẽ ra được số bé hơn, nếu chuỗi cứ tăng dần thì xoá số cuối cùng)
2. Xóa số tại vị trí đó
3. In ra vị trí số cần xóa và chuỗi số nhỏ nhất

*/

#include <bits/stdc++.h>
using namespace std;

int findDeleteIndex(string s) {
    int iN = s.size();
    for (int i = 0; i < iN - 1; i++) { // Duyệt từ trái sang phải
        if (s[i] > s[i + 1]) { // Nếu số đứng trước lớn hơn số đứng sau
            return i; // Trả về vị trí số cần xóa
        }
    }
    return iN - 1; // Nếu không tìm được vị trí số lớn nhất để xóa, trả về vị trí cuối cùng
}

int main() {
    string s;

    cin >> s;

    int indexToRemove = findDeleteIndex(s);

    string result = s.substr(0, indexToRemove) + s.substr(indexToRemove + 1);

    cout << "Index to remove: " << indexToRemove << endl;
    cout << "Result: " << result << endl;

    return 0;
}
