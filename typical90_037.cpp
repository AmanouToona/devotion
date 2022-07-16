#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
struct LazySegmentTree {
    const T INF = numeric_limits<T>::max();
    const T MINF = numeric_limits<T>::min();  // minus inf

    int n;           // 葉の数
    vector<T> data;  // 完全二分木の配列
    vector<T> lazy;  // 遅延データを入れる完全二分木の配列

    LazySegmentTree(int n_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
        data.resize(2 * n - 1, MINF);
        lazy.resize(2 * n - 1, MINF);  // lazy 0 が空の状態と定義する
    }

    // node k の遅延評価
    void eval(int k, int l, int r) {
        if (lazy[k] != MINF) {
            data[k] = lazy[k];

            if (r - l > 1) {  // 葉ノードでないならば
                lazy[2 * k + 1] = lazy[k];
                lazy[2 * k + 2] = lazy[k];
            }
        }
        lazy[k] = MINF;
    }

    void update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;

        eval(k, l, r);

        if (r <= a || l >= b) return;

        if (a <= l && r <= b) {
            lazy[k] = x;
            eval(k, l, r);
        } else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            data[k] = max(data[2 * k + 1], data[2 * k + 2]);
        }
    }

    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        // [a, b) の範囲が要求範囲
        // k: 現在見るノードの番号
        // 探索範囲 [l, r)

        if (r <= a || l >= b) return MINF;

        eval(k, l, r);
        if (a <= l && r <= b) return data[k];
        T value_l = query_sub(a, b, 2 * k + 1, l, (l + r) / 2);
        T value_r = query_sub(a, b, 2 * k + 2, (l + r) / 2, r);
        return max<T>(value_l, value_r);
    }
};

int main() {
    int W, N;
    cin >> W >> N;

    vector<tuple<int, int, ll>> data;
    for (int i = 0; i < N; i++) {
        int l, r;
        ll v;
        cin >> l >> r >> v;
        data.push_back(make_tuple(l, r, v));
    }

    LazySegmentTree<ll> segt(W);
    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, LLONG_MIN));
    dp[0][0] = 0LL;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 0;
        for (int j = 0; j <= W; j++) segt.update(j, j + 1, dp[i - 1][j]);
        for (int j = 0; j <= W; j++) {
            int l, r;
            ll v;
            tie(l, r, v) = data[i - 1];
            dp[i][j] = dp[i - 1][j];

            if (j - l < 0) continue;
            if (l - r >= W) continue;

            int temp = l;
            l = max(0, j - r);
            r = max(0, j - temp);

            dp[i][j] = max<ll>(segt.query(l, r + 1) + v, dp[i][j]);
        }
    }

    if (dp[N][W] <= 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << dp[N][W] << endl;
}