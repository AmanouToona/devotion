#include<bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> dw{-1, 0, 1, 0};
vector<int> dh{0, 1, 0, -1};


int dfs (vector<vector<char>> &c, vector<vector<bool>> &t, int h, int w, int sh, int sw) {
    // 一番最初の入力の処理
    if (c[h][w] == '#') return -1;

    if (w == sw && h == sh) return 0;

    if (sw < 0 && sh < 0) {
        sw = w;
        sh = h;
    }


    int res = -1;
    for (int i = 0; i < 4; i++) {
        int vw = w + dw[i];
        int vh = h + dh[i];

        // 領域内か?
        if (vw < 0 || vw >= c[0].size()) continue;
        if (vh < 0 || vh >= c.size()) continue;
        
        if (!t[vh][vw]) continue;

        // 入り
        t[vh][vw] = false;
        int temp = dfs(c, t, vh, vw, sh, sw);

        // 出
        t[vh][vw] = true;

        if (temp == -1) continue;
        res = max(res, 1 + temp);
    }

    return res;

}



int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> c(H, vector<char>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> c[h][w];
        }
    }

    int ans = 0;
    vector<vector<bool>> t(H, vector<bool>(W, true));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            ans = max(ans, dfs(c, t, h, w, -1, -1));
        }
    }

    
    if (ans < 3) cout << -1 << endl;
    else cout << ans << endl; 
}
