#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;


ll pow(ll x, ll n) {
    // x ** n
    ll res = 1;
    while(n > 0) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;

        res %= MOD;
        x %= MOD;
    }
    return res;
}



int main () {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = 1;

    ans = pow(2LL, n);
    ans -= 1;


    ll nca = 1;
    for (ll i  = n; i > (n  - a); i--) {
        nca *= i;
        nca %= MOD;
    }
    for (ll i = 1; i <= a; i++) { 
        nca *= pow(i, MOD - 2);
        nca %= MOD;
    }

    ll ncb = 1;
    for (ll i  = n; i > (n  - b); i--) {
        ncb *= i;
        ncb %= MOD;
    }
    for (ll i = 1; i <= b; i++) { 
        ncb *= pow(i, MOD - 2);
        ncb %= MOD;
    }

    // cout << ans << endl;
    // cout << nca << endl;
    // cout << ncb << endl;

    cout << (ans - nca - ncb + 2 * MOD) % MOD << endl;

}