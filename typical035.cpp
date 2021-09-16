#include<bits/stdc++.h>
using ll = long long;
using namespace std;


struct LCA {
    vector<int> dist;  // rootからの距離
    vector<vector<int>> parent; // parent[k][u] := u の 2^k 先の親
    LCA(vector<vector<int>> &G) {
        int K = 0;
        while ((1 << K) < G.size()) K++;

        parent.assign(K, vector<int>(G.size(), -1));
        dist.assign(G.size(), -1);
        dfs(0, -1, 0, G);

        for (int k = 1; k < K; k++) {
            for (int v = 0; v < G.size(); v++) {
                if (parent[k - 1][v] < 0) parent[k][v] = -1;
                else parent[k][v] = parent[k - 1][parent[k - 1][v]];
            }
        }
    }

    void dfs(int v, int p, int d, vector<vector<int>> &G) {  // root からの距離 と 2^0 個先の親を求める
        dist[v] = d;
        parent[0][v] = p;
        for (int u: G[v]) {
            if (u == p) continue;
            dfs(u, v, d + 1, G);
        }
    }

    int query(int u, int v) {  // u, v の共通祖先を返す
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深い

        int K = parent.size();
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }

        if (u == v) return u;

        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }

        return parent[0][u];
    }

    int get_dist(int u, int v) { // u, v の距離を返す
        return dist[u] + dist[v] - 2 * dist[query(u, v)];
    }

};


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

    LCA lca(G);

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

        if (K == 2) {
            cout << lca.get_dist(V[0], V[1]) << endl;
        } else if (K == 3) {
            cout << (lca.get_dist(V[0], V[1]) + lca.get_dist(V[1], V[2]) + lca.get_dist(V[2], V[0])) / 2 << endl;
        }

    }

}
