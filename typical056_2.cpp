#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, S;
    cin >> N >> S;
    
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;

    for (int n = 0; n < N; n++) {
        for (int s = 0; s < S; s++) {
            if (dp[n][s]) {
                if (dp[n][s] && s + A[n] <= S) dp[n + 1][s + A[n]] = true;
                if (dp[n][s] && s + B[n] <= S) dp[n + 1][s + B[n]] = true;
            }
        }
    }

    if (!dp[N][S]) {
        cout << "Impossible" << endl;
        return 0;
    }

    string res(N, '?');
    int pos = S;
    for (int n = N - 1; n >= 0; n--) {
        if (pos - B[n] >= 0 && dp[n][pos - B[n]]) {
            res[n] = 'B';
            pos -= B[n];
        } else {
            res[n] = 'A';
            pos -= A[n];
        }
    }

    cout << res << endl;
    return 0;

}