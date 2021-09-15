#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll dp[200000][3];


void dfs(int v, int p, vector<vector<int>> &G, vector<char> &c) {// v: now num, p parent num
    ll val1 = 1, val2 = 1;
    for (int u: G[v]) {
        if (u == p) continue;
        dfs(u, v, G, c);

        if (c[v] == 'a') {
            val1 *= (dp[u][0] + dp[u][2]);
            val2 *= (dp[u][0] + dp[u][1] + 2 * dp[u][2]);
        } else {
            val1 *= (dp[u][1] + dp[u][2]);
            val2 *= (dp[u][0] + dp[u][1] + 2 * dp[u][2]);
        }

        val1 %= MOD;
        val2 %= MOD;
    }

    if (c[v] == 'a') {
        dp[v][0] = val1;
        dp[v][1] = 0;
        dp[v][2] = val2 - val1 + MOD;
    } else {
        dp[v][0] = 0;
        dp[v][1] = val1;
        dp[v][2] = val2 - val1 + MOD;
    }

    dp[v][0] %= MOD;
    dp[v][1] %= MOD;
    dp[v][2] %= MOD;

}


int main() {
    int N;
    cin >> N;

    vector<char> c(N);
    for (int i = 0; i < N; i++) cin >> c[i];

    vector<vector<int>> G(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, -1, G, c);

    cout << dp[0][2] << endl;

}