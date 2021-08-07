#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    ll P;
    cin >> N >> K >> P;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // 半分全列挙
    vector<pair<ll, int>> H1;
    vector<vector<ll>> H2(K + 1, vector<ll>());
    for (int i = 0; i < (1 << (N / 2)); i++) {
        ll value = 0, items = 0;
        for (int j = 0; j < N / 2; j++) {
            if ((i >> j) & 1) {
                value += A[j];
                items ++;
            }
        }
        H1.push_back(make_pair(value, items));
    }

    for (int i = 0; i < (1 << (N - (N / 2))); i++) {
        ll value = 0, items = 0;
        for (int j = 0; j < (N - (N / 2)); j++) {
            if ((i >> j) & 1) {
                value += A[N / 2 + j];
                items++;
            }
        }
        if (items > K) continue;
        H2[items].push_back(value);
    }

    for (int i = 0; i <= K; i++) {
        sort(H2[i].begin(), H2[i].end());
    }

    ll ans = 0;
    for (auto [h1, h1_items]: H1) {
        if (K - h1_items < 0) continue;
        int left = -1, right = H2[K - h1_items].size();

        while(right - left > 1) {
            int mid = (right + left) / 2;
            if (H2[K - h1_items][mid] > P - h1) right = mid;
            else left = mid;
        }

        ans += right;
    }

    cout << ans << endl;

}