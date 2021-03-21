#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
    if (x % y == 0) return y;

    return gcd(y, x % y);
}


int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    vector<bool> num(51, true);
    num[0] = false, num[1] = false;
    for (int i = 2; i < 51; i++) {
        for (int j = 2 * i; j < 51; j+=i) {
            num[j] = false;
        }
    }

    ll ans= 0;
    vector<int> prime;
    for (int i = 2; i < 51; i++) {
        if (num[i]) prime.push_back(i);
    }

    for (ll bit = 1; bit < (1 << prime.size()); bit++) {
        ll candidate = 1;
        for (ll j = 0; j < prime.size(); j++) {
            if (bit & (1 << j)) {
                candidate *= prime[j];
            }
        }
        bool flag = true;
        for (auto x: X) {
            if (gcd(x, candidate) != 1) {continue;}
            else {flag = false; break;}
        }
        if (flag) {ans = candidate; break;}
    }

    cout << ans << endl;

}