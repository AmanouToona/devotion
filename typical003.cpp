#include <bits/stdc++.h>
using namespace std;
using ll = long long;


tuple<int, int> bfs(vector<vector<int>>& edge, int start) {
    // goal と距離を戻す
    queue<pair<int, int>> q;
    
    int dist, goal;
    vector<bool> footprint(edge.size(), false);
    footprint[start] = true;

    for (auto node: edge[start]) {
        q.push(make_pair(node, 1));
        footprint[node] = true;
    }

    while(!q.empty()) {
        int u_node = q.front().first;
        dist = q.front().second;
        q.pop();
        goal = u_node;

        for (auto v_node: edge[u_node]) {
            if (footprint[v_node]) continue;
            q.push(make_pair(v_node, dist + 1));
            footprint[v_node] = true;
        }
    }
    return make_tuple(goal, dist);
}



int main() {
    int N;
    cin >> N;

    vector<vector<int>> edge(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    auto [farthest, _] = bfs(edge, 0);
    auto [__, dist] = bfs(edge, farthest);

    cout << dist + 1 << endl;

}
