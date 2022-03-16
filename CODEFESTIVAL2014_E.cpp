#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> R(N);
    for (int i = 0; i < N; i++) cin >> R[i];

    // dp[] up = 0, down = 1
    vector<vector<int>> dp(N + 1, vector<int>(2, 1E6));

    dp[1][0] = R[0];
    dp[1][1] = R[0];
    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 0; i < N; i++) {
        // fill down
        for (int j = N; j > 0; j--) {
            if (dp[j - 1][0] == 1E6) continue;
            if (dp[j - 1][0] > R[i]) {
                dp[j][1] = R[i];
                break;
            }
            if (dp[j - 1][0] > R[i]) {
                dp[j - 1][1] = R[i];
                break;
            }
        }

        // fill up
        for (int j = N; j > 0; j--) {
            if (dp[j - 1][1] == 1E6) continue;
            if (dp[j - 1][1] < R[i]) {
                dp[j][0] = R[i];
                break;
            }
            if (dp[j - 1][1] < R[i]) {
                dp[j - 1][0] = R[i];
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (dp[i][0] != 1E6 || dp[i][1] != 1E6) ans = i;
    }

    if (ans < 3) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
}