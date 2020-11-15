#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a;
    cin >> N;
    vector<int> A; 
    vector<long long> dp(N, pow(10, 10)); dp.at(0) = 0;

    for (int i = 0; i < N; i++) {
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < N - 1; i++) {
        if (i + 1 < N && dp[i] + abs(A.at(i) - A.at(i + 1)) < dp[i + 1]) 
            dp[i + 1] = dp[i] + abs(A.at(i) - A.at(i + 1));
        if (i + 2 < N && dp[i] + abs(A.at(i) - A.at(i + 2)) < dp[i + 2])
            dp[i + 2] = dp[i] + abs(A.at(i) - A.at(i + 2));
    }

    cout << dp.at(dp.size() - 1) << endl;

}
