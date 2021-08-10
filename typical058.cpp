#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const MOD = 1e5;


int nxt_digit(int x) {
    int res = x;
    while(x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}


int main() {
    ll N, K;
    cin >> N >> K;

    vector<int> nxt(MOD);
    for (int i = 0; i < MOD; i++) {
        nxt[i] = nxt_digit(i) % MOD;
    }

    vector<int> time_stamp(MOD, -1);
    int cnt = 0, pos = N;
    while(time_stamp[pos] == -1) {
        time_stamp[pos] = cnt;
        pos = nxt[pos];
        cnt++;
    }

    int cycle = cnt - time_stamp[pos];

    if (K > time_stamp[pos]) {
        K = time_stamp[pos] + (K - time_stamp[pos]) % cycle;
    }

    int answer = -1;
    for (int i = 0; i < MOD; i++) {
        if (time_stamp[i] == K) {
            answer = i;
            break;
        }
    }

    cout << answer << endl;
}
