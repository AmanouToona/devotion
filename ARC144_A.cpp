#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = LLONG_MAX;

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

    ll ans= INF;
    vector<int> prime;
    for (int i = 2; i < 51; i++) {
        if (num[i]) prime.push_back(i);
    }

    for (ll bit = 1; bit < (1 << prime.size()); bit++) {
        ll candidate = 1;
        for (ll j = 0; j < prime.size(); j++) {
            if ((bit >> j) & 1) {
                candidate *= prime[j];
            }
        }

        bool flag = true;
        for (auto x: X) {
            if (gcd(candidate, x) != 1) {continue;}
            else {flag = false; break;}
        }
        if (flag) {ans = min<ll>(ans, candidate);}
    }

    cout << ans << endl;

}

/*
14
13 41 37 14 35 23 21 19 11 29 17 31 43 47
87841397512641630
20496326086283047

*/


