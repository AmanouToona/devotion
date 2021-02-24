#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, C, K;
    cin >> N >> C >> K;

    int bus = 0;
    priority_queue<int, vector<int>, greater<int>> que;

    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    sort(T.begin(), T.end());

    for(auto t: T) {

        while(!que.empty() && t - que.top() > K) {
            bus++;
            for (int i = 0; i < C; i++) {
                if (!que.empty()) que.pop();
                else break;
            }
        }

        que.push(t);
    }

    while(!que.empty()) {
        bus++;
        for (int i = 0; i < C; i++) {
            if(!que.empty()) que.pop();
            else break;
        }
    }

    cout << bus << endl;

}
