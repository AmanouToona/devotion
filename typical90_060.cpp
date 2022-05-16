#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> B1(N), B2(N);

    // 左から最長増加部分列
    vector<int> dp;
    dp.push_back(A[0]);
    B1[0] = 0;
    for (int i = 1; i < N; i++) {
        int a = A[i];
        int n = lower_bound(dp.begin(), dp.end(), a) - dp.begin();

        B1[i] = n;
        if (n >= dp.size())
            dp.push_back(a);
        else
            dp[n] = a;
    }

    // 右から最長増加部分列
    dp.clear();
    dp.push_back(A.back());
    B2[N - 1] = 0;
    for (int i = 1; i < N; i++) {
        int a = A[N - 1 - i];
        int n = lower_bound(dp.begin(), dp.end(), a) - dp.begin();

        B2[N - 1 - i] = n;
        if (n >= dp.size())
            dp.push_back(a);
        else
            dp[n] = a;
    }

    int ans = 0;
    for (int k = 0; k < N; k++) {
        ans = max(ans, B1[k] + B2[k] + 1);
    }
    cout << ans << endl;
}