#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
    vector<int> p, rank, member_size;

   public:
    UnionFind(int n) : p(n), rank(n, 0), member_size(n, 1) {
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

    int same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return member_size[find(x)]; }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> T(Q), X(Q), Y(Q), V(Q);
    for (int i = 0; i < Q; i++) cin >> T[i] >> X[i] >> Y[i] >> V[i];

    vector<vector<int>> G(N + 1);
    map<pair<int, int>, int> m;
    for (int i = 0; i < Q; i++) {
        if (T[i] == 1) continue;
        G[X[i]].push_back(Y[i]);
        G[Y[i]].push_back(X[i]);

        if (X[i] < Y[i]) {
            m[make_pair(X[i], Y[i])] = V[i];
        } else {
            m[make_pair(Y[i], X[i])] = V[i];
        }
    }

    vector<int> Azero(N + 1, INT_MAX), Aone(N + 1, INT_MAX);
    for (int i = 1; i <= N; i++) {
        if (Azero[i] == INT_MAX) {
            Azero[i] = 0;
            Aone[i] = 1;
        }

        for (int v : G[i]) {
            int s;
            if (v < i) {
                s = m[make_pair(v, i)];
            } else {
                s = m[make_pair(i, v)];
            }

            if (Azero[v] != INT_MAX) {
                Azero[i] = s - Azero[v];
                Aone[i] = s - Aone[v];
            } else {
                Azero[v] = s - Azero[i];
                Aone[v] = s - Aone[i];
            }
        }
    }

    UnionFind uf(N + 1);
    for (int i = 0; i < Q; i++) {
        int x = X[i], y = Y[i], v = V[i];

        if (T[i] == 0) {
            uf.unite(x, y);
            continue;
        }

        if (!uf.same(x, y)) {
            cout << "Ambiguous" << endl;
            continue;
        }

        ll ans = 1ll * Azero[y] + 1ll * (v - Azero[x]) / (Aone[x] - Azero[x]) *
                                      (Aone[y] - Azero[y]);
        cout << ans << endl;
    }

    cout << "" << endl;
}