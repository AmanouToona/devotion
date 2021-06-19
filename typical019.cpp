#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int solver(int l, int r, vector<vector<int>> & dp, vector<int> & A) {
    // 区間[l, r] を取り除くときの最小コストを返す

    if (dp[l][r] != -1) return dp[l][r];

    int res = INT_MAX;
    for (int i = l + 1; i < r; i+=2) {
        res = min(res, solver(l, i, dp, A) + solver(i + 1, r, dp, A));
    }

    res = min(res, solver(l + 1, r - 1, dp, A) + abs(A[r] - A[l]));

    dp[l][r] = res;

    return dp[l][r];
}


int main() {
    int N;
    cin >> N;
    vector<int> A(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> A[i];
    }

    // 区間dp  -1初期化　区間[l, r] を取り除くときの最小コストを記録する
    // 答えは 区間 [0, 2N - 1] の値となる
    vector<vector<int>> dp(2 * N, vector<int>(2 * N, -1));
    for (int i = 0; i < 2 * N - 1; i++) {
        dp[i][i + 1] = abs(A[i] - A[i + 1]);
    }

    int ans = solver(0, 2 * N - 1, dp, A);

    cout << ans << endl;
}
