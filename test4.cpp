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

/* Mã giả
Input: iN, iC, iM
Algorithm:
    - totalCandies <- iN / iC
    - wrappers <- totalCandies
    - while (wrappers >= iM) 
        do {
            - newCandies <- wrappers / iM
            - totalCandies <- totalCandies + newCandies
            - wrappers <- wrappers % iM + newCandies
        }
    - In ra totalCandies
*/

#include<bits/stdc++.h>
using namespace std;

int iN, iC, iM;

int main() {
    cin >> iN >> iC >> iM;
    
    int totalCandies = iN / iC; // Số kẹo ban đầu Bob có thể mua
    int wrappers = totalCandies; // Số giấy gói kẹo Bob có
    
    while (wrappers >= iM) { // Lặp lại cho đến khi số giấy gói không đủ để đổi kẹo
        int newCandies = wrappers / iM; // Số kẹo mới Bob có thể nhận được
        totalCandies += newCandies; // Cộng số kẹo mới vào tổng số kẹo
        wrappers = wrappers % iM + newCandies; // Cập nhật số giấy gói kẹo còn lại
    }

    /*
        Để an toàn thì em duyệt như trên, có thể in trực tiếp ra (iN / iC) / iM + (iN / iC)
    */
    
    cout << totalCandies;
}