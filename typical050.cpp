#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll const MOD = 1e9 + 7;


int main() {
    int N, L;
    cin >> N >> L;

    vector<ll> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j: {1, L}) {
            if (i + j > N) continue;
            dp[i + j] += dp[i];
            dp[i + j] %= MOD;
        }
    }

    cout << dp[N] << endl;

}