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

    int n;           // 葉の数
    vector<T> data;  // 完全二分木の配列

    SegmentTree(int n_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
        data.resize(2 * n - 1);
        for (int i = 0; i < data.size(); i++) data[i] = INF;
    }

    void update(int i, T x) {
        i += n - 1;
        data[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        // [a, b) の範囲が要求範囲
        // k: 現在見るノードの番号
        // 探索範囲 [l, r)

        if (r <= a || l >= b) return 0;

        if (a <= l && r <= b) return data[k];
        T value_l = query_sub(a, b, 2 * k + 1, l, (l + r) / 2);
        T value_r = query_sub(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(value_l, value_r);
    }
};

int main() {
    ll MOD = pow_ll(2, 20);

    int Q;
    cin >> Q;

    vector<int> A(MOD, -1);
    SegmentTree<int> S(MOD);
    for (int i = 0; i < MOD; i++) {
        S.update(i, i);
    }
    int INF = INT_MAX;
    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;

        x--;
        x %= MOD;

        if (t == 1) {
            int m;
            int pos = S.query(x, MOD - 1);
            if (pos == INF) {
                pos = S.query(0, x);
            }
            A[pos] = x;
            S.update(pos, INF);
        } else {
            int pos = x % MOD;
            cout << A[pos] << endl;
        }
    }
}
