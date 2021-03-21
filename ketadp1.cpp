#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int dp[100][2][2];  // digit, samller, appear 3
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    dp[0][1][0] = 0;
    dp[0][1][1] = 0;

    string N;
    cin >> N;

    int digit = N.size();

    vector<int> n;
    for (int i = 0; i < digit; i++) {
        n.push_back(N[i] - '0');
    }

    for(int i = 0; i < digit; i++) {
        for(int smaller = 0; smaller < 2; smaller++) {
            for(int k = 0; k < 2; k++) {
                for(int x = 0; x <= (smaller ? 9: n[i]); x++) {
                    dp[i + 1][smaller || x < n[i]][j || x == 3] += dp[i][smaller][k];
                } 
            }
        }
    }

    cout << dp[digit][0][1] + dp[digit][1][1] << endl;

}