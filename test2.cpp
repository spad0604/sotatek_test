/* Bài 2: Kiểm tra số hoàn hảo
Input: Số nguyên n
Output: "n is a perfect number" nếu n là số hoàn hảo, "n is not a perfect number" nếu n không phải là số hoàn hảo

Algorithm:
1. Nếu n <= 0, báo lỗi
2. Tính tổng các ước của n (không tính n)
    - Duyệt từ 1 đến căn bậc 2 của n (Vì ước của n chỉ có giá trị lớn nhất là căn bậc 2 của n)
    - Gán iPair = n / i
    - Nếu i là ước của n thì iPair = n / i cũng là ước của n (i * iPair = n)
    - Nếu i và iPair là 2 ước đối xứng nhau thì cộng i và iPair vào iResult (Phải kiểm tra i và iPair không phải là n)
    - Nếu iN là số chính phương thì chỉ cộng i vào iResult (Vì nếu iN là số chính phương thì i = iPair)
3. Nếu tổng các ước bằng n (iResult == iN), thì n là số hoàn hảo, ngược lại thì n không phải là số hoàn hảo
*/
#include <bits/stdc++.h>
using namespace std;

int iN, iResult = 0;

int main() {
    cin >> iN;

    if(iN <= 0) {
        cout << "Error: n must be positive";
    } else {
        for(int i = 1; i <= sqrt(iN); i++) {
            if(iN % i == 0) {
                int iPair = iN / i; // iPair là số đối xứng của i (tức là i * iPair = iN)

                if(i != iPair) { // Nếu i và iPair là 2 ước đối xứng nhau
                    if(i != iN) iResult += i;  //Chỉ cộng i vào iResult nếu i không phải là iN

                    if(iPair != iN) iResult += iPair; //Chỉ cộng iPair vào iResult nếu iPair không phải là iN
                } else { // Nếu iN là số chính phương
                    if(i != iN) iResult += i; //Chỉ cộng i vào iResult nếu i không phải là iN
                }
            }
        }

        if(iResult == iN) {
            cout << "n is a perfect number";
        } else {
            cout << "n is not a perfect number";
        }
    }

    return 0;
}
