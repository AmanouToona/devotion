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
    int H, W;
    cin >> H >> W;
    int Q;
    cin >> Q;

    vector<int> dh = {0, 1, 0, -1};
    vector<int> dw = {1, 0, -1, 0};

    vector<vector<bool>> red(H, vector<bool>(W, false));

    UnionFind uf(H * W);

    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            r--, c--;

            red[r][c] = true;
            for (int i = 0; i < 4; i++) {
                int vr = r + dh[i];
                int vc = c + dw[i];

                if (vr < 0 || vr >= H) continue;
                if (vc < 0 || vc >= W) continue;

                if (!red[vr][vc]) continue;

                uf.unite(r * W + c, vr * W + vc);
            }

        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;

            if (!red[ra][ca] || !red[rb][cb]) {
                cout << "No" << endl;
            } else if (uf.same(ra * W + ca, rb * W + cb)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}