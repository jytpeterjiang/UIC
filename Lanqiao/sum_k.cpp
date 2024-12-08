#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    
    // 输入数组
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // 前缀和及其余数计数
    unordered_map<int, int> remainder_count;
    remainder_count[0] = 1; // 处理从头开始的情况
    int prefix_sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += num[i];
        int remainder = prefix_sum % k;

        // Normalize remainder to be positive
        if (remainder < 0) {
            remainder += k;
        }

        // 如果当前的余数已经出现过，则累加出现的次数
        cnt += remainder_count[remainder];

        // 更新余数的出现次数
        remainder_count[remainder]++;
    }

    cout << cnt << endl;
    return 0;
}
