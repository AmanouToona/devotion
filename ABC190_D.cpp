# include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll ans = 0;
    for (ll i = 1; (i * i) <= (2 * N); i++) {
        if ((2 * N) % i != 0) continue;
        if (i % 2 == ((2 * N / i) % 2)) continue;
        ans += 2;
    }
    cout << ans << endl;
    return 0;
}
