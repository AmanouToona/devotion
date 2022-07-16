#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> g(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        g[A].push_back(B);
        g[B].push_back(A);
    }

    vector<bool> color(N, false);
    vector<bool> fp(N, false);
    queue<int> q;

    q.push(0);
    fp[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (fp[v]) continue;
            color[v] = !color[u];

            q.push(v);
            fp[v] = true;
        }
    }

    int true_count = 0;
    for (bool b : color)
        if (b) true_count++;

    vector<int> ans;
    if (true_count >= N / 2) {
        for (int i = 0; i < N; i++) {
            if (color[i]) ans.push_back(i + 1);
        }
    } else {
        for (int i = 0; i < N; i++) {
            if (!color[i]) ans.push_back(i + 1);
        }
    }

    for (int i = 0; i < N / 2; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
}