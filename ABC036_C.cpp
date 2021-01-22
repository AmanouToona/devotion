#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    priority_queue<int, vector<int>, greater<int>> que;
    map<int, int> mp;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        que.push(A[i]);
    }

    int counter = 0;
    while (!que.empty()) {
        if (mp.count(que.top()) != 0) {
            que.pop();
            continue;
        } else {
            mp[que.top()] = counter;
            que.pop();
            counter ++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << mp[A[i]] << endl;
    }
}
