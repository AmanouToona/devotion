#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll pow_ll(ll a, ll n) {
    ll res = 1;
    while(n > 0) {
        if (n & 1) res *= a;
        a *= a;
        n = (n >> 1);
    }
    return res;
}


int main() {
    ll N, P;
    cin >> N >> P;

    ll loop_ans = 1;
    ll final_ans = 1;

    if (N == 1) {
        cout << P << endl;
        return 0;
    }
    if (N > 50) {
        cout << 1 << endl;
        return 0;
    }

    while (1) {
        loop_ans++;
        ll ansn = pow_ll(loop_ans, N);
        if (ansn > P) break;
        if (P % ansn == 0) final_ans = loop_ans;
    }

    cout << final_ans << endl;

}

/*
304653014089 420894703852
*/
