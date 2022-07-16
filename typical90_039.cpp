#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int pos, int pre, vector<int> &dp, vector<vector<int>> &G) {
    dp[pos] = 1;
    for (int v : G[pos]) {
        if (v == pre) continue;
        dfs(v, pos, dp, G);
        dp[pos] += dp[v];
    }
    return;
}

ll solve(int pos, int pre, vector<int> &dp, vector<vector<int>> &G) {
    ll ans = 0;
    int N = G.size();

    for (int v : G[pos]) {
        if (v == pre) continue;
        ans += 1ll * dp[v] * (N - dp[v]);
        ans += solve(v, pos, dp, G);
    }
    return ans;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dp(N, 0);
    dfs(0, -1, dp, G);

    ll ans = solve(0, -1, dp, G);
    cout << ans << endl;
}