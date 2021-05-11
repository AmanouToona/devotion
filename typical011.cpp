#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<tuple<int, int, int>> work;
    for (int i = 0; i < N; i++) {
        int d, c, s;
        cin >> d >> c >> s;
        work.push_back(make_tuple(d, c, s));
    }

    sort(work.begin(), work.end());

    vector<int> D(N), C(N), S(N);
    for (int i = 0; i < N; i++) {
        D[i] = get<0>(work[i]);
        C[i] = get<1>(work[i]);
        S[i] = get<2>(work[i]);
    }

    int max_d = *max_element(D.begin(), D.end());
    vector<vector<ll>> dp(N + 1, vector<ll>(max_d + 1, 0));

    // dp
    for (int i = 0; i < N; i++) {  // お仕事 i + 1
        for (int j = 1; j <= max_d; j++) {
            if (j - C[i] >= 0 && D[i] >= j){
                dp[i + 1][j] = max<ll>(dp[i + 1][j], dp[i][j - C[i]] + S[i]);
            }
            dp[i + 1][j] = max<ll>(dp[i + 1][j], dp[i][j]);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= max_d; i++) {
        ans = max<ll>(ans, dp[N][i]);
    }

    cout << ans << endl;
}

// 1744196082
// 2402188366
