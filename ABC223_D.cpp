#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> mem(N, 0);
    vector<vector<int>> g(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        mem[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < N; i++) {
        if (mem[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()) {
        int u = q.top();
        q.pop();

        ans.push_back(u + 1);

        for (int v: g[u]) {
            mem[v]--;
            if (mem[v] == 0) q.push(v);
        }
    }

    if (ans.size() < N) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl ;
}