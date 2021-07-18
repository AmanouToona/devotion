#include<bits/stdc++.h>
using ll = long long;
using namespace std;


struct state {
    int dir, x, y;
};


int main() {
    int H, W;
    cin >> H >> W;

    int rs, cs, rt, ct;
    cin >> rs >> cs;
    cin >> rt >> ct;
    rs--; cs--; rt--; ct--;

    vector<string> S(H);
    for (int h = 0; h < H; h++) {
        cin >> S[h];
    }

    vector<int> dh = {0, 1, 0, -1};
    vector<int> dw = {1, 0, -1, 0};
    vector<vector<vector<ll>>> dist(H, vector<vector<ll>>(W, vector<ll>(4, INT_MAX)));
    for (int i = 0; i < 4; i++) {
        dist[rs][cs][i] = 0;
    }

    queue<state> q;
    for (int i = 0; i < 4; i++) {
        q.push({i, rs, cs});
    }

    while(!q.empty()) {
        auto [dir, uh, uw] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int vh = uh + dh[i];
            int vw = uw + dw[i];

            if (vh < 0 || vh >= H) continue;
            if (vw < 0 || vw >= W) continue;
            if (S[vh][vw] == '#') continue;

            int v_dist = dist[uh][uw][dir];
            if (i != dir) v_dist++;

            for (int j = 0; j < 4; j++) {
                dist[uh][uw][i] = min<ll>(dist[uh][uw][i], v_dist);
            }

            if (v_dist >= dist[vh][vw][i]) continue;
            dist[vh][vw][i] = v_dist;
            q.push({i, vh, vw});
        }
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < 4; i++) {
        ans = min<ll>(ans, dist[rt][ct][i]);
    }

    cout << ans << endl;
}
