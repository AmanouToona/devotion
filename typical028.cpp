#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cusum(1002, vector<int>(1002, 0));

    for (int i = 0; i < N; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        cusum[lx][ry]++;
        cusum[rx][ry]--;
        cusum[lx][ly]--;
        cusum[rx][ly]++;
    }

    // 累積和
    for (int h = 0; h < 1002; h++) {
        for (int w = 0; w < 1001; w++) {
            cusum[h][w + 1] += cusum[h][w];
        }
    }

    for (int h = 1001; h > 0; h--) {
        for (int w = 0; w < 1002; w++) {
            cusum[h - 1][w] += cusum[h][w];
        }
    }

    vector<int> ans(N + 1, 0);
    for (int h = 0; h < 1002; h++) {
        for (int w = 0; w < 1002; w++) {
            ans[cusum[h][w]]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
}
