#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> used(200000, false);
vector<bool> res(200000, false);

void dfs(int u, vector<vector<int>> &G, bool parity) {
    for (auto v: G[u]) {
        if (used[v]) continue;
        used[v] = true;
        res[v] = !parity;
        dfs(v, G, !parity);
    }
}


int main() {
    int N;
    cin >> N;

    vector<vector<int>> G(N, vector<int>());

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    used[0] = true;
    res[0] = true;
    dfs(0, G, true);

    int true_count = 0;
    for (int i = 0; i < N; i++) {
        if (res[i]) true_count++;
    }


    int i = 0;
    int counter = 0;
    while (counter < N / 2) {
        int ans = i;
        ans++;
        if (true_count >= N / 2 && res[i]) {
            if (counter) {cout << " ";}
            cout << ans;
            counter++;
        } else if (true_count < N / 2 && !res[i]) {
            if (counter) {cout << " ";}
            cout << ans;
            counter++;
        }
        i++;
    }
   cout << endl;

}
