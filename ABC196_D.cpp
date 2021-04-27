#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dfs(vector<vector<bool>> & is_empty, int A, int B, int h, int w) {
    int H = is_empty.size();
    int W = is_empty[0].size();

    if (A < 0 || B < 0) return 0;

    if (w >= W) {
        w = 0;
        h++;
    }

    if (h >= H) return 0;

    if (h == H - 1 && w == W - 1) {
        if (!is_empty[h][w]) return 1;  // 最後のマスが A を用いて敷かれていた
        if (A == 0 && B == 1) return 1;  // 最後のマスを B を用いて敷くことができる
        return 0;  // 最後のマスが敷かれておらず、A しか残っていないため敷くことができない
    }

    if (!is_empty[h][w]) return dfs(is_empty, A, B, h, w + 1);  // 現在地がすでに敷かれているので処理は必要ない

    ll ans = 0;
    // B を敷く
    is_empty[h][w] = false;
    ans += dfs(is_empty, A, B - 1, h, w + 1);

    // A を横に敷く;
    if (w + 1 < W && is_empty[h][w + 1]) {
        is_empty[h][w + 1] = false;
        ans += dfs(is_empty, A - 1, B, h, w + 1);
        is_empty[h][w + 1] = true;
    }

    // A を縦に敷く
    if (h + 1 < H && is_empty[h + 1][w]) {
        is_empty[h + 1][w] = false;
        ans += dfs(is_empty, A - 1, B, h, w + 1);
        is_empty[h + 1][w] = true;
    }

    is_empty[h][w] = true;

    return ans;
}


int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<bool>> is_empty(H, vector<bool>(W, true));

    cout << dfs(is_empty, A, B, 0, 0);

}
