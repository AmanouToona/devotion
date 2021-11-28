#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    vector<ll> X(N);
    for (ll i = 0; i < N; i++) cin >> X[i];

    ll ans = 0;
    for (ll i = 0; i < N - 1; i++) {
        ll dist = X[i + 1] - X[i];

        if (dist * A < B) {
            ans += dist * A;
        } else {
            ans += B;
        }
    }

    cout << ans << endl;

}