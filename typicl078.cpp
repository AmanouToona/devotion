#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        sort(G[i].begin(), G[i].end());
        if (G[i].size() == 0) continue;
        if (G[i][0] >= i) continue;
        if (G[i].size() >= 2 && G[i][1] <= i) continue;
        ans++;
    }

    cout << ans << endl;

}