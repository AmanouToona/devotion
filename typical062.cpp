#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> g(N, vector<int>());
    queue<int> q;
    vector<bool> used(N, false);

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;

        if (A == i || B == i) {
            q.push(i);
            used[i] = true;
        }
        g[A].push_back(i);
        g[B].push_back(i);
    }

    vector<int> ans;
    while(! q.empty()) {
        int u = q.front();
        q.pop();

        ans.push_back(u);

        for (int v: g[u]) {
            if (used[v]) continue;
            q.push(v);
            used[v] = true;
        }
    }

    reverse(ans.begin(), ans.end());

    if (ans.size() == N) {
        for (int a: ans) {
            cout << a + 1 << endl;
        }
    } else {
        cout << -1 << endl;
    }

}