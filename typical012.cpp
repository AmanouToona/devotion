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
    int H, W, Q;
    cin >> H >> W;
    cin >> Q;

    UnionFind Square(H * W);
    vector<vector<bool>> red(H, vector<bool>(W, false));
    vector<int> dw = {0, 1, 0, -1};
    vector<int> dh = {1, 0, -1, 0};

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;
        if (type == 1) {
            int r, c;
            cin >> r >> c;
            r--;
            c--;
            red[r][c] = true;

            for (int i = 0; i < 4; i++) {
                if (r + dw[i] < 0 || r + dw[i] >= H) continue;
                if (c + dh[i] < 0 || c + dh[i] >= W) continue;
                if (red[r + dw[i]][c + dh[i]]) {
                    Square.unite(r * W + c, (r + dw[i]) * W + c + dh[i]);
                }
            }

        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;

            bool can = Square.same(ra * W + ca, rb * W + cb);
            can = (can && red[ra][ca] && red[rb][cb]);
            if (can) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
