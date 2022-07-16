#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j - A[i - 1] >= 0 && dp[i - 1][j - A[i - 1]]) dp[i][j] = true;
            if (j - B[i - 1] >= 0 && dp[i - 1][j - B[i - 1]]) dp[i][j] = true;
        }
    }

    if (!dp[N][S]) {
        cout << "Impossible" << endl;
        return 0;
    }

    string ans(N, '?');
    int pos = S;
    for (int i = N - 1; i >= 0; i--) {
        if (pos - A[i] >= 0 && dp[i][pos - A[i]]) {
            ans[i] = 'A';
            pos -= A[i];
        } else {
            ans[i] = 'B';
            pos -= B[i];
        }
    }
    cout << ans << endl;
    return 0;
}
