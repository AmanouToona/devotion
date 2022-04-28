#include <bits/stdc++.h>
using namespace std;

vector<int> dh = {-1, 0, 1, 0};
vector<int> dw = {0, -1, 0, 1};

int dfs(vector<string>& C, int uh, int uw, int sh, int sw) {
    int ret = INT_MIN;

    for (int i = 0; i < 4; i++) {
        int vh = uh + dh[i];
        int vw = uw + dw[i];

        if (vh == sh && vw == sw) {
            ret = max(ret, 1);
            continue;
        }

        if (vh < 0 || vh >= C.size()) continue;
        if (vw < 0 || vw >= C[0].size()) continue;
        if (C[vh][vw] == '#') continue;

        C[uh][uw] = '#';
        ret = max(ret, dfs(C, vh, vw, sh, sw) + 1);
        C[uh][uw] = '.';
    }

    return ret;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> C(H);
    for (int h = 0; h < H; h++) cin >> C[h];

    int ans = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (C[h][w] == '#') continue;
            ans = max(ans, dfs(C, h, w, h, w));
        }
    }

    if (ans < 4) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}