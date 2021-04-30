#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll powll (ll a, ll b) {
    ll res = 1;
    if (b == 0) return res;

    while(b > 0) {
        if (b & (1ll)) {
            res *= a;
        }

        a *= a;
        b >>= 1;
    }

    return res;

}


int main() {
    ll N;
    cin >> N;

    set<ll> num;
    for (ll i = 2; i <= sqrt(N); i++) {
        for (ll j = 2; powll(i, j) <= N; j++) {
            num.insert(powll(i, j));
        }
    }

    cout << N - num.size() << endl;
}