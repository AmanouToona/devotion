#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> T(N);
    int t_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> T[i];
        t_sum += T[i];
    }

    sort(T.begin(), T.end());
    int t_max = T[T.size() - 1];

    int n_size = t_max * N + 1;
    vector<bool> dp(n_size, false);
    dp[0] = true;

    for (int t: T) {
        for (int i = t_max * N; i >= 0; i--) {
            if (!dp[i]) continue;
            if (i + t > t_max * N) continue;
            dp[i + t] = true;
        }
    }

    int ans;
    for (int i = (t_sum + 1) / 2; i < t_max * N + 1; i++) {
        if (dp[i]) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

}
