#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const int MOD = 998244353;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}



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
    int N;
    cin >> N;

    vector<int> f(N);
    for (int i = 0; i < N; i++) {
        cin >> f[i];
        f[i]--;
    }

    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        uf.unite(i, f[i]);
    }

    int unions = 0;
    for (int i = 0; i < N; i++) {
        if (uf.find(i) == i) unions++;
    }

    long long fac[N + 1], finv[N + 1], inv[N + 1];
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }

    ll ans = 0;
    for (int i = 1; i <= unions; i++) {
        ans += 1LL * fac[unions] * finv[i] % MOD * finv[unions - i] % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

}
