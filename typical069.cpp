#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1e9 + 7;

ll pow (ll N, ll K) {
    ll res = 1;
    ll ref = K;
    while (N > 0) {
        if (N & 1) {
            res *= ref;
            res %= MOD;
        }
    
        ref *= ref;
        ref %= MOD;
        N >>= 1;
    }
    return res;
}



int main() {
    ll N, K;
    cin >> N >> K;

    if (N == 1) {
        cout << K << endl;
        return 0;
    } else if (N == 1) {
        cout << K * (K - 1) << endl;
        return 0;
    }

    ll ans = K * (K - 1);
    ans %= MOD;

    ans *= pow(N - 2, K - 2);
    ans %= MOD;

    cout << ans << endl;

}
