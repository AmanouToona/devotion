#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int sum_digit(int K) {
    int res = 0;
    while (K > 0) {
        res += K % 10;
        K /= 10;
    }
    return res;
}

int main() {
    int K;
    cin >> K;

    int sum_d = sum_digit(K);
    if (sum_d % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> dp(K + 1);
    dp[0] = 1;
    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i + j > K) break;
            dp[i + j] += dp[i];
            dp[i + j] %= MOD;
        }
    }
    cout << dp[K] << endl;
}