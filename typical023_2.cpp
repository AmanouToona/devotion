#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;


int main() {
    int H, W;
    cin >> H >> W;

    vector<string> C(H);
    for (int h = 0; h < H; h++) {
        cin >> C[h];
    }

    vector<vector<int>> dp(H * W, vector<int>(1 << (W + 1), 0));

    dp[0][0] = 1;
    for (int p = 0; p < (H * W - 1); p++) {
        for (int i = 0; i < (1 << (W + 1)); i++) {
            int next1 = (i >> 1), next2 = (i >> 1) + (1 << W);

            dp[p + 1][next1] += dp[p][i];
            dp[p + 1][next1] %= MOD;

            if (C[p / W][p % W] == '#') continue;
            if (i & 1 && p / W >= 1 && p % W >= 1) continue;
            if ((i >> 1) & 1) continue;
            if ((i >> 2) & 1 && p % W < W - 1) continue;
            if ((i >> W) & 1) continue; 

            dp[p + 1][next2] += dp[p][i];
            dp[p + 1][next2] %= MOD;

        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << (W + 1)); i++) {
        ans += dp[H * W - 1][i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;

}
