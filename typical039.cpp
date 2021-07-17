#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll dfs (vector<vector<ll>> &graph, vector<ll> &dp, ll u, ll p) {
    if (dp[u] != -1) return dp[u];
    
    ll res = 1;
    for (ll v: graph[u]) {
        if (v == p) continue;
        res += dfs(graph, dp, v, u);
    }

    dp[u] = res;
    return dp[u];
};


int main() {
    ll N;
    cin >> N;

    vector<vector<ll>> graph(N);
    for (ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll> dp(N, -1);
    dfs(graph, dp, 0, -1);

    ll ans = 0;
    for (ll a: dp) {
        ans += a * (N - a);
    }

    cout << ans << endl;

}
