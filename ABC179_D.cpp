#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;
vector<int> dp(200005);

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> S;
    for (int i = 0; i < K; i++){ 
        int L, R;
        cin >> L >> R;

        S.push_back(make_pair(L, R));
    }

    vector<int> cusum(200005, 0);

    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        if (i >= 1) {
            cusum[i] += cusum[i - 1];
            cusum[i] %= mod;
            dp[i] = cusum[i];
        }

        for (int j = 0; j < S.size(); j++) {
            int L, R;

            L = S[j].first;
            R = S[j].second;
            if (i + L < N) cusum[i + L] += dp[i]; 
            cusum[i + L] %= mod;
            if (i + R < N) cusum[i + R + 1] -= dp[i]; 
            cusum[i + R + 1] = (cusum[i + R + 1] + mod) %mod;
        }
    }    

    cout << dp[N - 1] << endl;
}