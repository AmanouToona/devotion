#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> table;

    for (int h = 0; h < H; h++) {
        string row;
        cin >> row;
        table.push_back(row);
    }

    vector<vector<int>> ans_tb(H, vector<int>(W, INT_MAX));
    if (table[0][0] == '.') ans_tb[0][0] = 0;
    else ans_tb[0][0] = 1;
    vector<pair<int, int>> d = {{0, 1}, {1, 0}};

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            for (auto [dh, dw] : d) {
                int vh = h + dh;
                int vw = w + dw;
                if (vh >= H || vw >= W) continue;

                if (table[vh][vw] == '#') {
                    if (table[h][w] == '#') {
                        ans_tb[vh][vw] = min(ans_tb[h][w], ans_tb[vh][vw]);
                    } else {
                        ans_tb[vh][vw] = min(ans_tb[h][w] + 1, ans_tb[vh][vw]);
                    }
                } else {
                    ans_tb[vh][vw] = min(ans_tb[h][w], ans_tb[vh][vw]);
                }
            }
        }
    }
    cout << ans_tb[H - 1][W - 1] << endl;
}
