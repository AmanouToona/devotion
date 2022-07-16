#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> dp(1002, vector<ll>(1002, 0));

    for (int i = 0; i < N; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        dp[ly][lx]++;
        dp[ly][rx]--;
        dp[ry][lx]--;
        dp[ry][rx]++;
    }

    for (int h = 0; h < 1002; h++) {
        for (int w = 0; w < 1001; w++) {
            dp[h][w + 1] += dp[h][w];
        }
    }

    for (int h = 0; h < 1001; h++) {
        for (int w = 0; w < 1002; w++) {
            dp[h + 1][w] += dp[h][w];
        }
    }

    vector<int> res(N + 1, 0);
    for (int w = 0; w < 1002; w++) {
        for (int h = 0; h < 1002; h++) {
            int p = dp[w][h];
            res[p]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i] << endl;
    }
}