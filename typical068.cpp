#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
    vector<int> p, rank, member_size;

    public: UnionFind(int n): p(n), rank(n, 0), member_size(n, 1){
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (p[x] == x) return x;
        p[x] = find(p[x]);
        return p[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (rank[x] <= rank[y]) {
            p[x] = y;
            member_size[y] += member_size[x];
        } else {
            p[y] = x;
            member_size[x] += member_size[y];
        }

        if (rank[x] == rank[y]) {
            rank[y]++;
        }
        return;
    } 
    
    int same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return member_size[find(x)];
    }

};


int main() {
    string no = "Ambiguous";

    // 入力
    int N, Q;
    cin >> N >> Q;
    
    vector<int> T(Q), X(Q), Y(Q), V(Q);
    for (int q = 0; q < Q; q++) cin >> T[q] >> X[q] >> Y[q] >> V[q];
    for (int q = 0; q < Q; q++) X[q]--, Y[q]--;

    vector<vector<int>> G(N, vector<int>());
    vector<vector<int>> sum(N, vector<int>(N));
    vector<bool> cango(N, false);
    for (int q = 0; q < Q; q++) {
        if (T[q] == 1) continue;
        G[X[q]].push_back(Y[q]);
        G[Y[q]].push_back(X[q]);
        cango[X[q]] = true;
        cango[Y[q]] = true;
    

        sum[X[q]][Y[q]] = V[q];
        sum[Y[q]][X[q]] = V[q];
    }

    // クエリ先読み　解答準備
    vector<int> Azero(N), Aone(N);
    for (int n = 0; n < N; n++) {
        if (!cango[n]) continue;

        cango[n] = false;
        queue<int> q;
        q.push(n);
        Azero[n] = 0;
        Aone[n] = 1;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v: G[u]) {
                if (!cango[v]) continue;
                cango[v] = false;
                q.push(v);
                
                Azero[v] = sum[u][v] - Azero[u];
                Aone[v] = sum[u][v] - Aone[u];
            }
        }
    }

    // クエリ処理
    UnionFind unionfind(N);
    for (int q = 0; q < Q; q++) {
        if (T[q] == 0) {
            unionfind.unite(X[q], Y[q]);
        } else {
            if (!unionfind.same(X[q], Y[q])) {
                cout << no << endl;
            } else {
                ll ans = 1LL * Aone[Y[q]] + (V[q] - Aone[X[q]]) * (Aone[X[q]] - Azero[X[q]]) / (Aone[Y[q]] - Azero[Y[q]]);
                cout << ans << endl;
            }
        }
    }

}
