#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dijkstra(vector<vector<pair<int, int>>> &G, vector<ll> &dist, int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    const ll INF = (1LL << 60);
    for (int i = 0; i < dist.size(); i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    Q.push(make_pair(0, start));
    while(!Q.empty()) {
        auto [d, u] = Q.top(); Q.pop();

        if (dist[u] < d) continue;
        for (auto[v, cost]: G[u]) {
            ll next_d = d + cost;
            if (next_d > dist[v]) continue;
            dist[v] = next_d;
            Q.push(make_pair(next_d, v));
        }
    }
}


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> G(N);
    for (int m = 0; m < M; m++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        G[A].push_back(make_pair(B, C));
        G[B].push_back(make_pair(A, C));
    }

    vector<ll> dist1(N), dist2(N);
    dijkstra(G, dist1, 0);
    dijkstra(G, dist2, N - 1);

    for (int i = 0; i < N; i++) {
        cout << dist1[i] + dist2[i] << endl;
    }


}