#include<bits/stdc++.h>
using ll = long long;
using namespace std;


void dfs(int u, vector<int> & used, vector<int> &vs, vector<vector<int>> &G) {
    used[u] = true;

    for (auto v: G[u]) {
        if (used[v]) continue;
        dfs(v, used, vs, G);
    }

    vs.push_back(u);

}

void rdfs(int u, vector<int> &used, vector<int> &cmp, vector<vector<int>> &RG, int k) {
    used[u] = true;
    cmp[u] = k;

    for (auto v: RG[u]) {
        if (used[v]) continue;
        rdfs(v, used, cmp, RG, k);
    }
}



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> G(N, vector<int>()), RG(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        RG[b].push_back(a);
    }

    vector<int> cmp(N, -1);  // 強連結成分グループ
    vector<int> used(N, false);  // 探索済み? 
    vector<int> vs;  // 帰りがけ並び順


    // dfs 全探索
    for (int i = 0; i < N; i++) {
        if (!used[i]) dfs(i, used, vs, G);
    }

    // 初期化
    for (int i = 0; i < N; i++) used[i] = false;

    // 逆順 dfs 強連結成分グループ分け
    int k = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (!used[vs[i]]) rdfs(vs[i], used, cmp, RG, k);
        k++;
    }

    map<int, int> m;
    for (auto group: cmp) {
        if (m.count(group) == 0) m[group] = 1;
        else m[group] += 1;
    }    

    ll ans = 0;
    for (auto p: m) {
        int value = p.second;
        // if (value <= 1) continue;
        ans += 1LL * value * (value - 1) / 2;
    }

    cout << ans << endl;


}