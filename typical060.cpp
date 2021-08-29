#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1 << 19];

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> lis_l(N, INT_MAX), lis_r(N, INT_MAX);
    vector<int> count_l(N, 0), count_r(N, 0);

    for (int i = 0; i < N; i++) {
        int pos = lower_bound(lis_l.begin(), lis_l.end(), A[i]) - lis_l.begin();
        lis_l[pos] = A[i];
        count_l[i] = pos + 1;
    }
    for (int i = N - 1; i >= 0; i--) {
        int pos = lower_bound(lis_r.begin(), lis_r.end(), A[i]) - lis_r.begin();
        lis_r[pos] = A[i];
        count_r[i] = pos + 1;
    }

    reverse(count_r.begin(), count_r.end());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        
        ans = max(ans, count_l[i] + count_r[i] - 1);
    }

    cout << ans << endl;

}
