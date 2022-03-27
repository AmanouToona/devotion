#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll N, ll X, vector<ll> &dpp, vector<ll> &dpx) {
    if (X == 0) return 0;
    if (N == 0) return 1;

    if (X <= dpx[N - 1] + 1) return solve(N - 1, X - 1, dpp, dpx);
    if (X == dpx[N - 1] + 2) return solve(N - 1, X - 1, dpp, dpx) + 1;
    if (X >= 2 + 2 * dpx[N - 1]) return dpp[N - 1] * 2 + 1;
    return dpp[N - 1] + 1 + solve(N - 1, X - dpx[N - 1] - 2, dpp, dpx);
}

int main() {
    ll N, X;
    cin >> N >> X;

    vector<ll> dpp(N + 1, 0), dpx(N + 1, 0);
    dpp[0] = 1;
    dpx[0] = 1;

    for (ll i = 0; i < N; i++) {
        dpp[i + 1] = dpp[i] * 2 + 1;
        dpx[i + 1] = dpx[i] * 2 + 3;
    }

    cout << solve(N, X, dpp, dpx) << endl;
}
