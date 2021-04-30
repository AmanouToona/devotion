#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<ll> p(N), q(N);
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        p[i] = x + y;
        q[i] = x - y;
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    ll ans = max<ll>(p[N - 1] - p[0], q[N - 1] - q[0]);

    cout << ans << endl;
}
