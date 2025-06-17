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
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] + mul;
            
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    string res = "";
    bool leadingZero = true;
    
    for(int i = 0; i < result.size(); i++) {
        if(result[i] != 0 || !leadingZero) {
            leadingZero = false;
            res += (result[i] + '0');
        }
    }
    
    return res.empty() ? "0" : res;
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
