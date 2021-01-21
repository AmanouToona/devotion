#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> bfs(vector<string> table, int sh, int sw) {
    int H, W;
    H = table.size();
    W = table[0].size();

    queue<vector<int>> que;
    que.push({sh, sw, 0});

    vector<vector<bool>> fp(H, vector<bool>(W, false));

    const int dw[4] = {1, 0, -1, 0};
    const int dh[4] = {0, 1, 0, -1};
    tuple<int, int, int> res;
    while(!que.empty()) {
        auto [uh, uw, dist] = que.front();
        res = make_tuple(uh, uw, dist);
        que.pop();
        for (int i = 0; i < 4; i++) {
            int vh = uh + dh[i];
            int vw = uw + dw[i];
            
            if (vh >= H || vh < 0|| vw >= W || vw < 0) continue;
            if (table[vh][vw] == '#') continue;

            fp[vh][vw] = true;
            que.push({vh, vw, dist + 1});
        }
    }
    return res;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> table;
    string s;
    for (int i = 0; i < H; i++) {
        cin >> s;
        table.push_back(s);
    }

    int s_h, s_w;  // start;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (table[h][w] == '.') {
                s_h = h;
                s_w = w;
                break;
            }
        }
    }

    //  bfs を 2回行って最遠点を求める


}