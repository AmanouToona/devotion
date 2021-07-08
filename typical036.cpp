#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<ll, ll>> P;
    vector<ll> X, Y;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        P.push_back(make_pair(x - y, x + y));
        X.push_back(x - y);
        Y.push_back(x + y);
    }

    sort(P.begin(),P.end());
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        q--;

        ll ans = 0;
        ll x = P[q].first, y = P[q].second;
        ans = max<ll>(abs(X[0] - x), abs(X[N - 1] - x));
        ans = max<ll>(ans, abs(Y[0] - y));
        ans = max<ll>(ans, abs(Y[N - 1] - y)); 

        cout << ans << endl;
    }
}
