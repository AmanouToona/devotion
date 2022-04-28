#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    string atcoder = "atcoder";

    vector<vector<ll>> dp(8, vector<ll>(N + 1, 0));
    for (int i = 0; i <= N; i++) dp[0][i] = 1;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j + 1] = dp[i + 1][j];
            if (S[j] == atcoder[i]) {
                dp[i + 1][j + 1] += dp[i][j + 1];
            }
            dp[i + 1][j + 1] %= MOD;
        }
    }
    cout << dp[7][N] << endl;
}
