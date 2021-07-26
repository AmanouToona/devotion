#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> dp(2, vector<int>(N - 1));
    dp[0][0] = 1;
    dp[1][0] = 1;

    for (int i = 1; i < N - 1; i++) {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[0][i - 1];
    }

    int minus = dp[1][N - 2];
    int plus = dp[0][N - 2];
    int tot = minus + plus;
    ll ans = 0;
    for (int i = 0; i < N; i ++) {
        if (i == 0) {
            ans += tot * A[0];
            ans %= MOD;
            continue;
        } else if (i == N - 1 || i == 1) {
            ans += plus * A[i];
            ans -= minus * A[i];
            ans %= MOD;
            continue;
        }

        ans += plus * A[i];
        ans -= (minus - 1) * A[i];
        ans %= MOD;

    }

    cout << ans << endl;

}