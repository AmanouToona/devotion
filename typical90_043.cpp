#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, -1, 0, 1};

int main() {
    int H, W;
    cin >> H >> W;

    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--;
    cs--;
    rt--;
    ct--;

    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<vi>> dp(H, vector<vi>(W, vi(4, INT_MAX)));

    // 初期化
    for (int i = 0; i < 4; i++) {
        dp[rs][cs][i] = 0;
    }

    deque<tuple<int, int, int>> q;
    for (int i = 0; i < 4; i++) {
        q.push_back(make_tuple(rs, cs, i));
    }

    while (!q.empty()) {
        auto [ur, uc, d] = q.front();
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            int vr = ur + dr[i];
            int vc = uc + dc[i];

            if (vr < 0 || vr >= H) continue;
            if (vc < 0 || vc >= W) continue;
            if (S[vr][vc] == '#') continue;

            int dcost = 0;
            if (d != i) dcost = 1;

            int cost = dp[ur][uc][d] + dcost;

            if (dp[vr][vc][i] <= cost) continue;

            dp[vr][vc][i] = cost;

            if (d == i) {
                q.push_front(make_tuple(vr, vc, i));
            } else {
                q.push_back(make_tuple(vr, vc, i));
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dp[rt][ct][i]);
    }
    cout << ans << endl;
}
