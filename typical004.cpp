#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W, 0));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> A[h][w];
        }
    }

    // 累積和
    vector<int> row(H, 0), col(W, 0);
    for (int h = 0; h < H; h++) {
        int cusum = 0;
        for (int w = 0; w < W; w++) {
            cusum += A[h][w];
        }
        row[h] = cusum;
    }

    for (int w = 0; w < W; w++) {
        int cusum = 0;
        for (int h = 0; h < H; h++) {
            cusum += A[h][w];
        }
        col[w] = cusum;
    }

    // 解答
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cout << row[h] + col[w] - A[h][w];
            if (w == W - 1) continue;
            cout << " ";
        }
        cout << endl;
    }

}