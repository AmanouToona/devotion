#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    priority_queue<int, vector<int>, less<int>> q;
    for (int i = 0; i < N; i++) q.push(A[i]);

    for (int i = 0; i < M; i++) {
        int a = q.top(); q.pop();
        q.push(a / 2);
    }

    ll ans = 0;
    while(!q.empty()) {
        ans += q.top();
        q.pop();
    }

    cout << ans << endl;

}