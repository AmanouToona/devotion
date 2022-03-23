#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> f(int x) {
    int b = x % 10;
    int a = x;
    while (x) {
        a = x;
        x /= 10;
    }
    return make_pair(a, b);
}

int main() {
    int N;
    cin >> N;

    map<pair<int, int>, ll> m;
    for (int i = 1; i <= N; i++) {
        pair<int, int> p = f(i);
        m[p]++;
    }

    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        pair<int, int> p = f(i);
        ans += m[make_pair(p.second, p.first)];
    }

    cout << ans << endl;
}
