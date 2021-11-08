#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const INF = INT_MAX;

int main() {
    int H, N;
    cin >> H >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(H + 1, INF));
    dp[0][H] = 0;

    for (int i = 0; i < N; i++) {
        for (int h = H; h >= 0; h--) {
            int nxt = max(0, h - A[i]);
            dp[i][nxt] = min<ll>(dp[i][nxt], dp[i][h] + B[i]);
            dp[i + 1][h] = min<ll>(dp[i + 1][h], dp[i][h]);
        }
    }

    ll ans = INF;
    for (int i = 0; i < N; i++) {
      ans = min(ans, dp[i][0]);  
    }

    cout << ans << endl;

}