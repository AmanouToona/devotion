#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    int P[H][W];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> P[i][j];
    }


    int ans = 0;
    // H についてのbit 全探索
    for (int bit = 0; bit < (1 << H); bit++){

        map<int, int> usable_col;
        int use_col = 0;
        for (int w = 0; w < W; w++) {
        
            bool flag = true;
            int col_num = -1;
            for (int h = 0; h < H; h++) {
                if (((bit >> h) & 1) == 0) continue;
                if (col_num == -1) col_num = P[h][w];
                if (col_num != P[h][w]) flag = false;
            }
            if (flag) {
                usable_col[col_num]++;
                use_col = max(use_col, usable_col[col_num]);
            }
        }

        int use_row = 0;
        for (int h = 0; h < H; h++) {
            if ((bit >> h) & 1) use_row++;
        }

        ans = max(ans, use_col * use_row);
    }

    cout << ans << endl;
}