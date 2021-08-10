#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<int> time_stamp(N, -1);
    int cnt = 0, pos = 0;
    while(time_stamp[pos] == -1) {
        time_stamp[pos] = cnt;
        pos = A[pos];
        cnt++;
    }

    int cycle = cnt - time_stamp[pos];
    if (K >= cnt) {
        K = time_stamp[pos] + (K - time_stamp[pos]) % cycle;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (time_stamp[i] == K) {
            ans = i;
            ans++;
        }
    }

    cout << ans << endl;

}