#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    ll ans = 1;
    for (int hw = 0; hw < H + W; hw++) {
        int count_dot = 0;
        int count_r = 0;
        int count_b = 0;

        for (int w = hw; w >= 0; w--) {
            int h = hw - w;
            if (w >= W) continue;
            if (h >= H) continue;

            if (S[h][w] == '.') count_dot++;
            else if (S[h][w] == 'R') count_r++;
            else count_b++;
        }
        if (count_r && count_b) ans = 0;
        else if (count_b == 0 && count_r == 0 && count_dot) {
            ans *= 2;
            ans %= MOD;
        }
    }

    cout << ans << endl;

}