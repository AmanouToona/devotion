#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> dp(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        dp[a] = -1;
    }

    dp[0] = 1;
    for (int i = 1; i < N + 1; i++) {
        if (dp[i] == -1) continue;
        if (dp[i - 1] != -1) {dp[i] += dp[i - 1];}
        dp[i] %= MOD;
        if (i >= 2 && dp[i - 2] != -1) {dp[i] += dp[i - 2];}
        dp[i] %= MOD;
    }

    if (dp[N] == -1) dp[N] = 0;

    cout << dp[N] << endl;

}