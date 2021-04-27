#include <bits/stdc++.h>
using namespace std;
using ll = long long;


bool judge(vector<ll> &H, vector<ll> &S, ll heigh) {
    vector<ll> sec_limit(H.size());  // 何秒以内に風船を割らなけらばならないか記録する
    for (int i = 0; i < sec_limit.size(); i++) {
        sec_limit[i] = (heigh - H[i]) / S[i];
        if (heigh < H[i]) return false;
    }

    sort(sec_limit.begin(), sec_limit.end());
    for (int i = 0; i < sec_limit.size(); i++) {
        if (sec_limit[i] < i) return false;  // 時間内に風船を割ることができない
    }

    return true;
}



int main() {
    int N;
    cin >> N;
    vector<ll> H(N), S(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i] >> S[i];
    }

    // 2分探索
    ll ng = 0, ok = 1ll * 1000000000 * 1000000 + 1000000000;
    cout << 1ll - ok << endl;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if (judge(H, S, mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}
