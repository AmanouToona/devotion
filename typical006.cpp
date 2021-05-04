#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    // 前計算 i 文字目以降で一番左にある alpabet の位置を記録する
    vector<vector<int>> dp(26, vector<int>(N, N));
    for (int i = N - 1; i >= 0; i--) {
        dp[S[i] - 'a'][i] = i;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = N - 1; j > 0; j--) {
            dp[i][j - 1] = min(dp[i][j], dp[i][j - 1]);
        }
    }


    // 問題を解く
    string ans = "";
    int left = 0;
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < 26; i++) {
            int limit = N - (K - k);  // 先頭から何文字目までを用いてよいか
            if (dp[i][left] <= limit) {
                ans.push_back('a' + i);
                left = dp[i][left] + 1;
                break;
            }
        }
    }

    cout << ans << endl;

}