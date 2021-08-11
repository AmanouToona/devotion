#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    int X, M;
    cin >> N >> X >> M;

    vector<int> time_stamp(M, -1);
    int pos = X, cnt = 1;
    while(time_stamp[pos] == -1) {
        time_stamp[pos] = cnt;
        pos = (1LL * pos * pos) % M;
        cnt++;
    }

    int cycle = cnt - time_stamp[pos];
    int start_cycle = time_stamp[pos];

    ll cycle_sum = 0;  // cum of num of 1 cycle
    for (int i = 0; i < M; i++) {
        if (time_stamp[i] >= start_cycle) {
            cycle_sum += i;
        }
    }

    ll cycle_count = 0;
    if (N > time_stamp[pos]) {
        cycle_count = (N - time_stamp[pos]) / cycle;
        N = time_stamp[pos] + (N - time_stamp[pos]) % cycle;
    }

    ll ans = 0;
    for (ll i = 0; i < M; i++) {
        if (time_stamp[i] <= N && time_stamp[i] >= 1) {
            ans += i;
        }
    }

    ans += cycle_sum * cycle_count;
    cout << ans << endl;

}