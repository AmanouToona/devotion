#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> P(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> P[i][j];
    }

    int ans = 0;
    for (int h = 1; h <= 1 << 8; h++) {
        map<int, int> m;
        for (int w = 0; w < W; w++) {
            bool can_use = true;
            int num = 0;
            for (int i = 0; i < H; i++) {
                if (((h >> i) & 1) == 0) continue;
                if (num == 0) {
                    num = P[i][w];
                    continue;
                }
                if (P[i][w] != num) can_use = false;
            }
            if (can_use) m[num]++;
        }

        int row = 0;
        for (int i = 0; i < H; i++) {
            if ((h >> i) & 1) row++;
        }

        for (auto [key, value] : m) {
            ans = max(value * row, ans);
        }
    }
    cout << ans << endl;
}