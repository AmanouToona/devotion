#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
struct BIT {
    // データ構造は 1-indexed であることに注意すること

    int n;
    vector<T> bit;

    BIT (int N) {
        n = N;
        bit = vector<T>(n, 0);
    }

    void add (int i, T x) {
        // 位置i に xを加算する処理
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }

    T sum(int i) {
        // 位置i までの総和を取得する処理
        T res = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            res += bit[idx];
        }
        return res;
    }
};



int main() {
    int N, M;
    cin >> N >> M;

    ll ans = 1LL * M * (M - 1) / 2;

    vector<int> L(M), R(M);
    for (int i = 0; i < M; i++) {
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
    }

    // pattern 1
    vector<int> end_point(N, 0);
    for (int i = 0; i < M; i++) {
        end_point[L[i]]++;
        end_point[R[i]]++;
    }

    ll ans_1 = 0;
    for (auto cnt: end_point) {
        ans_1 += 1LL * cnt * (cnt - 1) / 2;
    }

    // pattern 2
    vector<int> cusum_r(N, 0);
    for (auto r: R) {
        cusum_r[r]++;
    }

    for (int i = 1; i < N; i++) {
        cusum_r[i] += cusum_r[i - 1];
    }

    vector<int> sum_l(N, 0);
    for (auto l: L) {
        sum_l[l]++;
    }

    ll ans_2 = 0;
    for (int i = 0; i < N - 1; i++) {
        ans_2 += 1LL * sum_l[i + 1] * cusum_r[i];
    }

    // pattern 3
    vector<pair<int, int>> rl;
    for (int i = 0; i < M; i++) {
        rl.push_back(make_pair(R[i], L[i]));
    }

    sort(rl.begin(), rl.end());

    BIT<int> bit(N);
    ll ans_3 = 0;
    for (int i = 0; i < M; i++) {
        ll cr = rl[i].first, cl = rl[i].second;
        cr++; cl++;
        ans_3 += i - bit.sum(cl);
        bit.add(cl, 1);
    }


    ans -=  ans_1 + ans_2 + ans_3;

    cout << ans << endl;

}
