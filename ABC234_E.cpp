#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
T pow_ll(T x, T n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
};

int main() {
    ll X;
    cin >> X;

    vector<ll> anss;
    for (ll i = 0; i < 19; i++) {
        for (ll j = 1; j < 10; j++) {
            ll ans = 0;
            ll ii = i;
            while (ii >= 0) {
                ans += j * pow_ll<ll>(10, ii);
                ii -= 1;
            }
            anss.push_back(ans);
        }
    }

    for (ll res = 1; res < 10; res++) {
        for (ll s = 0; s < 10; s++) {
            ll ans = 0;
            ll ss = s;
            ll dig = 0;
            while (ss > 0) {
                ans += ss * pow_ll<ll>(10, dig);
                dig++;
                ss -= res;
                if (ans > 10) anss.push_back(ans);
            }

            ans = 0;
            ss = s;
            dig = 0;
            while (ss < 10) {
                ans += ss * pow_ll<ll>(10, dig);
                dig++;
                ss += res;
                if (ans > 10) anss.push_back(ans);
            }
        }
    }

    sort(anss.begin(), anss.end());
    auto iter = lower_bound(anss.begin(), anss.end(), X);
    auto idx = distance(anss.begin(), iter);
    cout << anss[idx] << endl;
}