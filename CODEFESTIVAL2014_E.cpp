#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> R(N);
    for (int i = 0; i < N; i++) cin >> R[i];

    // 最長増加部分列に近い考え方で実装する
    // dp[長さ][0: 大きい方の数字, 1: 小さい方の数字]
    vector<vector<int>> dp(N + 1, vector<int>(2, 1e6));
    dp[0][0] = R[0];
    dp[0][1] = R[0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // dp[][0]
            if (dp[j][1] < R[i] && dp[j + 1][0] != 1e6)
                dp[j + 1][0] = max(dp[j + 1][0], R[i]);
            else if (dp[j][1] < R[i])
                dp[j + 1][0] = R[i];

            // dp[][1]
            if (dp[j][0] > R[i] && dp[j][0] != 1e6)
                dp[j + 1][1] = min(dp[j + 1][1], R[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i][0] != 1e6 || dp[i][1] != 1e6) ans = i + 1;
    }

    if (ans < 3) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
}