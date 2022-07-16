#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    ll P;
    cin >> N >> K >> P;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<ll>> H1(21), H2(21);
    int mid = N / 2;

    for (int i = 0; i < (1 << mid); i++) {
        int count = 0;
        ll value = 0ll;

        for (int j = 0; j < mid; j++) {
            if (!((i >> j) & 1)) continue;
            count++;
            value += A[j];
        }
        H1[count].push_back(value);
    }

    for (int i = 0; i < (1 << (N - mid)); i++) {
        int count = 0;
        ll value = 0ll;

        for (int j = 0; j < (N - mid); j++) {
            if (!((i >> j) & 1)) continue;
            count++;
            value += A[j + mid];
        }
        H2[count].push_back(value);
    }

    for (int i = 0; i < H1.size(); i++) {
        sort(H1[i].begin(), H1[i].end());
        sort(H2[i].begin(), H2[i].end());
    }

    ll ans = 0;
    // for (int h = 0; h <= mid; h++) {
    //     for (ll v1 : H1[h]) {
    //         int pos1 =
    //             lower_bound(H2[K - h].begin(), H2[K - h].end(), P - v1 + 1) -
    //             H2[K - h].begin();
    //         ans += pos1;
    //     }
    // }

    for (int h = 0; h <= min(K, mid); h++) {
        for (int i = 0; i < (int)H1[h].size(); i++) {
            if (K - h > 20) continue;
            int pos1 = lower_bound(H2[K - h].begin(), H2[K - h].end(),
                                   P - H1[h][i] + 1) -
                       H2[K - h].begin();
            ans += (long long)pos1;
        }
    }

    cout << ans << endl;
}