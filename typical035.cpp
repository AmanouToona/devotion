#include<bits/stdc++.h>
using ll = long long;
using namespace std;


void dfs(int v, int p, vector<vector<int>> &G, vector<int> &dp) {
    for (int u: G[v]) {
        if (u == p) continue;
        dfs(u, v, G, dp);
        dp[v] += dp[u];
    }
}


int main() {
    int N;
    cin >> N;

    vector<vector<int>> G(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int K;
        cin >> K;

        vector<int> V(K);
        for (int k = 0; k < K; k++) {
            cin >> V[k];
            V[k]--;
        }

        vector<int> dp(N, 0);
        for (int k = 0; k < K; k++) {
            dp[V[k]] = 1;
        }

        dfs(0, -1, G, dp);

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (dp[i] >= 1 && dp[i] != K) ans++;
        }

        cout << ans << endl;
    }

}
