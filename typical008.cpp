#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    string atcoder = "atcoder";

    vector<vector<int>> dp(7 + 1, vector<int>(N + 1, 0));
    for (int col = 0; col < N + 1; col++) {
        dp[0][col] = 1;
    }

    for (int row = 1; row < 8; row++) {
        for (int col = 1; col < N + 1; col++) {
            if (atcoder[row - 1] == S[col - 1]) {
                dp[row][col] = dp[row - 1][col - 1] + dp[row][col - 1];
                dp[row][col] %= MOD;
            } else {
                dp[row][col] = dp[row][col - 1];
            }
        }
    }

    cout << dp[7][N] << endl;
    return 0;

}