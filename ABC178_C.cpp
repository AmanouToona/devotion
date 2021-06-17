#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll const MOD = 1000000007;

ll pow_mod(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
        }
        b >>= 1;
        a *= a;

        res %= MOD;
        a %= MOD;
    }
    return res;
}


int main() {
    ll N;
    cin >> N;

    // cout << pow_mod(10, N) << endl;
    // cout << pow_mod(8, N) << endl;
    // cout << pow_mod(9, N) << endl;

    ll ans = pow_mod(10, N) + pow_mod(8, N) - 2 * pow_mod(9, N);

    ans += 2 * MOD;
    ans %= MOD;
    cout << ans << endl;    

}