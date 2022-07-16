#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> g(N);

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        g[A].push_back(B);
        g[B].push_back(A);
    }

    // dfs
    queue<int> q;
    vector<int> dist(N, -1);

    q.push(0);
    dist[0] = 0;
    int last_node = 0;
    while (!q.empty()) {
        int u = q.front();
        last_node = u;
        q.pop();

        for (int v : g[u]) {
            if (dist[v] == 0) continue;
            dist[v] = 0;
            q.push(v);
        }
    }

    q.push(last_node);
    dist[last_node] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] != 0) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    int ans = *max_element(dist.begin(), dist.end());
    cout << ans << endl;
}