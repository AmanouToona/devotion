#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sum_digit(ll N) {
    ll res = 0;
    while (N > 0) {
        res += N % 10;
        N /= 10;
    }
    return res;
}

ll p = 1e5;

int main() {
    ll N, K;
    cin >> N >> K;

    map<ll, ll> m;
    while (K > 0) {
        K--;

        N += sum_digit(N);
        N %= p;

        if (m.count(N) == 0) {
            m[N] = K;
            continue;
        }

        K %= (m[N] - K);
    }
    cout << N << endl;
}