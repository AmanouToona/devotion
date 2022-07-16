#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp(a, b) make_pair(a, b)

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

    // 前処理
    for (int i = 0; i < Q; i++) {
        if (T[i] == 1) continue;
        int x = X[i], y = Y[i], v = V[i];

        G[x].push_back(y);
        G[y].push_back(x);

        m[mp(x, y)] = v;
        m[mp(y, x)] = v;
    }

    vector<ll> Azero(N + 1, LLONG_MAX), Aone(N + 1);
    for (int i = 1; i <= N; i++) {
        if (Azero[i] != LLONG_MAX) continue;
        Azero[i] = 0;
        Aone[i] = 1;

        queue<pair<int, int>> q;
        for (int v : G[i]) {
            q.push(mp(i, v));
        }

        while (!q.empty()) {
            auto [u, v] = q.front();
            q.pop();

            if (Azero[v] != LLONG_MAX) continue;

            int sum = m[mp(u, v)];
            Azero[v] = sum - Azero[u];
            Aone[v] = sum - Aone[u];

            for (int nxt_v : G[v]) {
                if (Azero[nxt_v] != LLONG_MAX) continue;
                q.push(mp(v, nxt_v));
            }
        }
    }

    // クエリ処理
    UnionFind uf(N + 1);
    for (int i = 0; i < Q; i++) {
        int x = X[i], y = Y[i], v = V[i], t = T[i];

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