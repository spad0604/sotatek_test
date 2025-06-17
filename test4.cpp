/* Bài 4: Tính số kẹo tối đa mà Bob có thể nhận được
Input:
- iN: Số kẹo ban đầu
- iC: Số tiền để mua 1 kẹo
- iM: Số giấy gói cần để đổi 1 kẹo

Output:
- Số kẹo tối đa mà Bob có thể nhận được

Algorithm:
1. Tính số kẹo Bob mua được ban đầu: iN / iC
2. Từ số kẹo mua được đó, chỉ cần chia cho iM để tính số kẹo mà Bob có thể nhận được thêm
3. Lặp lại cho đến khi số giấy gói không đủ để đổi kẹo
4. In ra số kẹo tối đa mà Bob có thể nhận được
*/

#include<bits/stdc++.h>
using namespace std;

int iN, iC, iM;

int main() {
    cin >> iN >> iC >> iM;
    
    int totalCandies = iN / iC;
    int wrappers = totalCandies;
    
    while (wrappers >= iM) {
        int newCandies = wrappers / iM;
        totalCandies += newCandies;
        wrappers = wrappers % iM + newCandies;
    }
    
    cout << totalCandies;
}