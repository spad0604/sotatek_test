// Bài 1: Tính n!
/*
Input: n (số nguyên không âm)
Output: n! (giai thừa của n)

Algorithm:
1. Khởi tạo mảng String sResult để lưu kết quả là một số nguyên lớn
2. Nếu n < 0, báo lỗi
3. Nếu n = 0, trả về 1
4. Nếu n > 0:
   - Gán sResult[0] = "1"
   - Với mỗi i từ 1 đến n:
     + Tính sResult[i] = sResult[i-1] * (i)
5. In ra sResult[n]
*/

/* Mã giả
Input: iN
Algorithm:
    function multiply(num1, num2)
        - len1 <- num1.size()
        - len2 <- num2.size()
        - result <- vector<int>(len1 + len2, 0)
        - for (i <- len1 - 1 to 0)
            do {
                - for (j <- len2 - 1 to 0)
                    do {
                        - mul <- (num1[i] - '0') * (num2[j] - '0')
                        - sum <- result[i + j + 1] + mul
                        - result[i + j + 1] <- sum % 10
                        - result[i + j] <- result[i + j] + sum / 10
                    }
        - res <- ""
        - leadingZero <- true
        - for (i <- 0 to result.size() - 1)
            do {
                - if (result[i] != 0 || !leadingZero)
                    - leadingZero <- false
                    - res <- res + result[i]
            }   
        - Trả về res.empty() ? "0" : res
    main()

    - If (iN < 0)
        - In ra "Error: n is negative"
    - If (iN == 0)
        - In ra "1"
    - else
        - sResult[0] <- "1"
        - for (i <- 1 to iN)
            do {
                - sResult[i] <- multiply(sResult[i-1], to_string(i))
            }
        - In ra sResult[iN]
*/

#include<bits/stdc++.h>
using namespace std;

int iN;
string *sResult;

string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    
    vector<int> result(len1 + len2, 0);
    
    for(int i = len1 - 1; i >= 0; i--) {
        for(int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0'); // Chuyển đổi về số nguyên và tính tích 2 số
            int sum = result[i + j + 1] + mul; // Tính tổng của tích và số ở vị trí hiện tại
            
            result[i + j + 1] = sum % 10; // Lưu phần dư vào vị trí hiện tại
            result[i + j] += sum / 10; // Lưu phần nhớ để cộng vào vị trí tiếp theo
        }
    }
    
    string res = "";
    bool leadingZero = true;
    
    for(int i = 0; i < result.size(); i++) { 
        if(result[i] != 0 || !leadingZero) { // Nếu số khác 0 hoặc không phải số 0 đầu tiên
            leadingZero = false; // Đánh dấu đã gặp số khác 0
            res += (result[i] + '0'); // Chuyển đổi về chuỗi và thêm vào kết quả
        }
    }
    
    return res.empty() ? "0" : res; // Nếu kết quả là chuỗi rỗng thì trả về "0", ngược lại thì trả về kết quả
}

int main() {
    cin >> iN;
    sResult = new string[iN + 1];

    if(iN < 0) {
        cout << "Error: n is negative";
        return 0;
    }
    if(iN == 0) {
        cout << "1";
        return 0;
    } else {
        sResult[0] = "1";
        for(int i = 1; i <= iN; i++) {
            sResult[i] = multiply(sResult[i - 1], to_string(i));
        }

        cout << sResult[iN];
    }

    delete[] sResult;
    return 0;
}
