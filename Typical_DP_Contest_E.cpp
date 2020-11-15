#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main() {
    string N;
    vector<int> n;
    int D, l;

    cin >> D;
    cin >> N;
    l = N.size();
    for (int i = 0; i < l; i++) {
        n.push_back(N.at(i) - '0');
    }
    
    // dp [digit][smaller][%D]
    vector<vector<vector<int>>> dp(10002, vector<vector<int>>(2, vector<int>(100, 0)));
    dp[0][0][0] = 1;

    for (int digit = 0; digit < l; digit++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int d = 0; d < D; d++) {
                for (int x = 0; x <= (smaller ? 9 : n.at(digit)); x++) {
                    // cout << "digit:" << digit << " smaller:" << smaller << " d:" << d << " x:" << x << " dp:" << dp[digit][smaller][d] << endl;
                    dp[digit + 1][smaller || x < n.at(digit)][(d + x) % D] += dp[digit][smaller][d];
                    dp[digit + 1][smaller || x < n.at(digit)][(d + x) % D] %= mod;
                }
            }
        }
    }

    int ans;
// 　　1以上の数値のうち条件を満たすものの個数を答える。0 % D = 0 は常に成り立つが 1以上であることを満たさないので 1を引く
    ans = dp.at(l).at(0).at(0) + dp.at(l).at(1).at(0) - 1;

    cout << ans << endl;

}
