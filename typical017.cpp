#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

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
    vector<int> cnt(N, 0);
    ll ans_3 = 0;
    for (int i = 0; i < M; i++) {
        ll cr = rl[i].first, cl = rl[i].second;
        for (int j= cl + 1; j < N; j++) {
            ans_3 += cnt[j];
        }
        cnt[cl]++;
    }

    ll ans = 1LL * M * (M - 1) / 2 - ans_1 - ans_2 - ans_3;

    cout << ans << endl;

}