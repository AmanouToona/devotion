#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct UnionFind {
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
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    UnionFind d(20000005);
    for (int i = 0; i < N; i++) {
        d.unite(A[i], A[N - 1 - i]);
    }

    int ans = 0;
    for (int i = 0; i < 20000005; i++) {
        if (d.p[i] != i) continue;
        if (d.size(i) == 0) continue;
        ans += d.size(i) - 1;
    }

    cout << ans << endl;

}