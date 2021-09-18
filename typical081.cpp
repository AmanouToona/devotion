#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> cusum(50001, vector<int>(5001, 0));
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cusum[a][b]++;
    }

    // 2次元累積和
    for (int i = 0; i < 5001; i++) {
        for (int j = 0; j < 5001; j++) {
            cusum[i][j + 1] += cusum[i][j];
        }
    }
    for (int i = 0; i < 5001; i++) {
        for (int j = 0; j <= 5001; j++) {
            cusum[i + 1][j] += cusum[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i + K <= 5000; i++) {
        for (int j = 1; j + K <= 5000; j++) {
            int population = cusum[i + K][j + K] - cusum[i + K][j - 1] - cusum[i - 1][j + K] + cusum[i - 1][j - 1];
            ans = max(ans, population);
        }
    }

    cout << ans << endl;
    return 0;

}
