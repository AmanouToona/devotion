#include <bits/stdc++.h>
using namespace std;

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
        data.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);  // lazy 0 が空の状態と定義する
    }

    // node k の遅延評価
    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            data[k] = lazy[k];

            if (r - l > 1) {  // 葉ノードでないならば
                lazy[2 * k + 1] = lazy[k];
                lazy[2 * k + 2] = lazy[k];
            }
        }
        lazy[k] = 0;
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

        if (r <= a || l >= b) return 0;

        eval(k, l, r);
        if (a <= l && r <= b) return data[k];
        T value_l = query_sub(a, b, 2 * k + 1, l, (l + r) / 2);
        T value_r = query_sub(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(value_l, value_r);
    }
};

int main() {
    int N;
    cin >> N;
}