#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    // n C r 用の前処理
    ll fac[N + 1], finv[N + 1], inv[N + 1];
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }



    for (int i = 0; i < N; i++) { // 間隔
        ll ans = 0;
        for (int j = 1; i * (j - 1) + j <= N; j++) {
            // n C r を求める
            int n = N - i * (j - 1);
            int r = j;

            ans += 1LL * fac[n] * finv[r] % MOD * finv[n - r] % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }

}