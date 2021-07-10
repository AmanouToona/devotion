#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct SegmentTree {
    const T inf = numeric_limits<T>::max();

    int n;  // データ数
    vector<T> data;  // 完全二分木の配列

    SegmentTree(int n_){
        int x = 1;
        while (x < n_) {
            x *= 2;
        }
        n = x;
        data.resize(2 * n - 1, 0);
    }

    void update (int i, T x) {
        i += n - 1;
        data[i] = max<T>(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = max<T>(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    T query(int a, int b) {
        a = max(a, 0);  // この問題だけの処理　面倒なのでここに入れた
        b = max(b, 0);
        return sub_query(a, b, 0, 0, n);   
    }

    T sub_query(int a, int b, int k, int left, int right) {
        if (b <= left || a >= right) return 0;
        if (a <= left && right <= b) return data[k];

        T vl = sub_query(a, b, 2 * k + 1, left, (left + right) / 2);
        T vr = sub_query(a, b, 2 * k + 2, (left + right) / 2, right);

        return max<T>(vl, vr);
    }

    T get_data(int i) {
        return data[i + n - 1];
    }
};



int main() {
    int W, N;
    cin >> W >> N;

    vector<SegmentTree<ll>> dp(N + 1, SegmentTree<ll>(W + 1));
    for (int i = 1; i <= N; i++) {
        ll L, R, V;
        cin >> L >> R >> V;

        for (int j = 1; j <= W; j++) {
            dp[i].update(j, dp[i - 1].get_data(j));
            if (j < L) continue;

            ll value_u = dp[i - 1].query(j - R, j - L + 1);
            if (value_u == 0 && j - R > 0) continue;
            dp[i].update(j, value_u + V);
        }
    }

    ll ans = dp[N].get_data(W);
    if (ans == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}
