#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<queue<int>> A(M);
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            a--;
            A[i].push(a);
        }
    }    
    
    queue<int> q;
    vector<vector<int>> mem(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int u = A[i].front();
        mem[u].push_back(i);
        A[i].pop();

        if (mem[u].size() != 2) continue;
        for (int v: mem[u]) q.push(v);
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if (A[u].size() == 0) continue;
        int color = A[u].front();
        mem[color].push_back(u);
        A[u].pop();

        if (mem[color].size() != 2) continue;
        for (int v: mem[color]) q.push(v);
    }



    for (int i = 0; i < M; i++) {
        if (A[i].size() != 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}