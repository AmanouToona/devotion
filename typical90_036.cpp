#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<ll> s;
    vector<ll> t;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        s.push_back(x + y);
        t.push_back(x - y);
    }

    ll s_min = *min_element(s.begin(), s.end());
    ll s_max = *max_element(s.begin(), s.end());
    ll t_min = *min_element(t.begin(), t.end());
    ll t_max = *max_element(t.begin(), t.end());

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        q--;

        ll ans = 0;
        ans = max<ll>(ans, abs(s_min - s[q]));
        ans = max<ll>(ans, abs(s_max - s[q]));
        ans = max<ll>(ans, abs(t_min - t[q]));
        ans = max<ll>(ans, abs(t_max - t[q]));
        cout << ans << endl;
    }
}