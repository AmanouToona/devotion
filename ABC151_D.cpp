#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> bfs(vector<string> table, int sh, int sw) {
    int H, W;
    H = table.size();
    W = table[0].size();
    vector<vector<bool>> fp(H, vector<bool>(W, false));

    queue<array<int, 3>> que;
    que.push({sh, sw, 0});

    const int dw[4] = {1, 0, -1, 0};
    const int dh[4] = {0, 1, 0, -1};
    tuple<int, int, int> res;

    while(!que.empty()) {
        auto [uh, uw, dist] = que.front();  que.pop();
        res = make_tuple(uh, uw, dist);

        for (int i = 0; i < 4; i++) {
            int vh; 
            vh = uh + dh[i];
            int vw = uw + dw[i];
            
            if (vh >= H || vh < 0|| vw >= W || vw < 0) continue;
            if (table[vh][vw] == '#') continue;
            if (fp[vh][vw] == true) continue;

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
    auto [s_h2, s_w2, dist2] = bfs(table, s_h, s_w);

    auto [g_h3, g_w3, dist3] = bfs(table, s_h2, s_w2);

    cout << dist3 << endl;

}