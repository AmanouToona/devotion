#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow_ll(ll x, ll n) {
    ll res = 1ll;
    while (n > 0) {
        if (n & 1) {
            res *= x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}

template <typename T>
struct SegmentTree {
    const T INF = numeric_limits<T>::max();
    const T MINF = numeric_limits<T>::min();  // minus inf

    ll n;           // 葉の数
    vector<T> data;  // 完全二分木の配列

    SegmentTree(ll n_) {
        ll x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
        data.resize(2 * n - 1);
        for (ll i = 0; i < data.size(); i++) data[i] = INF;
    }

    void update(ll i, T x) {
        i += n - 1;
        data[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    T query(ll a, ll b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(ll a, ll b, ll k, ll l, ll r) {
        // [a, b) の範囲が要求範囲
        // k: 現在見るノードの番号
        // 探索範囲 [l, r)

        if (r <= a || l >= b) return INF;

        if (a <= l && r <= b) return data[k];
        T value_l = query_sub(a, b, 2 * k + 1, l, (l + r) / 2);
        T value_r = query_sub(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(value_l, value_r);
    }
};

int main() {
    ll MOD = pow_ll(2, 20);

    ll Q;
    cin >> Q;

    vector<ll> A(MOD, -1);
    SegmentTree<ll> S(MOD);
    for (ll i = 0; i < MOD; i++) {
        S.update(i, i);
    }
    ll INF = numeric_limits<ll>::max();
    for (ll i = 0; i < Q; i++) {
        ll t, x;
        cin >> t >> x;

        ll h = x;
        h--;
        h %= MOD;

        if (t == 1) {
            ll m;
            ll pos = S.query(h, MOD);
            if (pos == INF) {
                pos = S.query(0, h);
            }
            A[pos] = x;
            S.update(pos, INF);
        } else {
            cout << A[h] << endl;
        }
    }
}

/*
4
1 1048577
1 1
2 2097153
2 3

1048577
-1
*/
