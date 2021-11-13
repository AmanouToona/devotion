#include<bits/stdc++.h>
using namespace std;
using ll = long long;


template <typename T>
struct SegmentTree {
    const T INF = numeric_limits<T>::max();
    const T MINF = numeric_limits<T>::min();

    int n;  // 葉の数
    vector<T> data;

    SegmentTree(int n_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
        data.resize(2 * n - 1);

        for (int i = 0; i < data.size(); i++) data[i] = 0;
    }

    void update(int i, T x) {
        i += n - 1;
        data[i] ^= x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = data[2 * i + 1] ^ data[2 * i + 2];
        }
    }

    T query(int a, int b) {return query_sub(a, b, 0, 0, n);}
    
    T query_sub(int a, int b, int k, int l, int r) {

        if (r <= a || l >= b) return 0;

        if (a <= l && r <= b) return data[k];

        T value_l = query_sub(a, b, 2 * k + 1, l, (l + r) / 2);
        T value_r = query_sub(a, b, 2 * k + 2, (l + r) / 2, r);
        return value_l ^ value_r;
    }
};



int main() {
    int N, Q;
    cin >> N >> Q;

    // vector<ll> A(N);
    // for (int i = 0; i < N; i++) cin >> A[i];

    SegmentTree<ll> st(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        st.update(i, a);
    }


    for (int i = 0; i < Q; i++) {
        int T, x, y;
        cin >> T >> x >> y;

        if (T == 1) {
            st.update(x - 1, y);
        } else {
            ll ans = st.query(x - 1, y);
            cout << ans << endl;
        }
    }
}