#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    ll ans = 1;
    for (ll i = 1; i * i <= M; i++) {
        if (M % i != 0) continue;
        if (i * N <= M) {
            ans = max(i, ans);
        }
        if (M / i * N <= M) {
            ans = max(M / i, ans);
        }
    }

    cout << ans << endl;
}