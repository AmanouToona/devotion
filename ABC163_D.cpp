#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long cusum(ll start, ll goal) {
    return (goal + start) * (goal - start + 1) / 2;
}

int main() {
    ll N, K, mod=pow(10, 9) + 7;
    cin >> N >> K;

    long long big, small, ans = 0;
    for (ll k = K; k <= N + 1; k++) {
        big = cusum(N - k + 1, N);
        small = cusum(0, k - 1);

        ans += big - small + 1;
        ans %= mod;
    }

    cout << ans << endl;

}