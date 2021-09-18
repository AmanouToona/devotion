#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll const MOD = 1e9 + 7;


int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> X(Q), Y(Q), Z(Q);
    vector<ll> W(Q);
    for (int i = 0; i < Q; i++) {
        cin >> X[i] >> Y[i] >> Z[i] >> W[i];
        X[i]--; Y[i]--; Z[i]--;
    }

    ll ans = 1;
    for (int i = 0; i < 60; i++) {
        ll count = 0;
        for (ll bit = 0; bit < (1 << N); bit++) {
            bool pass_q = true;
            for (int q = 0; q < Q; q++) {
                if (((bit >> X[q] & 1) | (bit >> Y[q] & 1) | (bit >> Z[q] & 1)) != ((W[q] >> i) & 1)) pass_q = false;
            }
            if (pass_q) count++;
        }
        ans *= count % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

}
