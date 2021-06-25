#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

// bool check(int h1, int w1, int h2, int w2) {
//     if (abs(h1 - h2) > 1 || abs(w1 - w2) > 1) true;
//     else false;
// }

bool check(vector<string> &C, ll i, int H, int W) {
    vector<int> DH = {0, 1};
    vector<int> DW = {-1, 0, 1};

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            
            int position = W * h + w;
            if (! ((i >> position) & 1)) continue;  // キングを置いていないならばスルー
            if (C[h][w] == '#') return false;


            for (auto dh: DH) {
                for (auto dw: DW) {
                    if (dh == 0 && dw == 0) continue;
                    if (h + dh >= H) continue;
                    if (w + dw >= W) continue;
                    if (w + dw < 0) continue;

                    int new_position = W * (h + dh) + (w + dw);
                    if (i >> new_position & 1) return false;

                }
            }

        }
    }

    return true;
}



int main() {
    int H, W;
    cin >> H >> W;

    vector<string> C(H);
    for (int h = 0; h < H; h++) {
        cin >> C[h];
    }

    vector<vector<int>> dp(H, vector<int>(W, 0));

    int ans = 0;
    for (ll i = 0; i < (1 << H * W); i++) {
        if (check(C, i, H, W)) ans++;
        cout << i << endl;
    }

    cout << ans << endl;

}
