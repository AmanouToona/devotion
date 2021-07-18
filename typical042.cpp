#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main() {
    int K;
    cin >> K;

    vector<vector<ll>> dp(K + 1, vector<ll>(9, 0));
    dp[K][0] = 1;

    for (int k = K; k > 0; k--) {
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (k - i < 0) continue;
                dp[k - i][(j + i) % 9] += dp[k][j];
                dp[k - i][(j + i) % 9] %= MOD;
            }
        }
    }

    cout << dp[0][0] << endl;

}
