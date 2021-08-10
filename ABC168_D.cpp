#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    vector<int> res(N, -1);
    res[0] = 0;
    queue<int> q;
    for (int v: G[0]) {
        q.push(v);
        res[v] = 0;
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: G[u]) {
            if (res[v] != -1) continue;
            q.push(v);
            res[v] = u;
        }
    }

    cout << "Yes" << endl;
    for (int i = 1; i < N; i++) {
        cout << res[i] + 1<< endl;
    }
}