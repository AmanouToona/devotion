#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll n, ll N, vector<ll> &v) {
    n *= 10;
    if (n >= N) return;

    for (int ones_place : {3, 5, 7}) {
        if (n + ones_place <= N) {
            v.push_back(n + ones_place);
            dfs(n + ones_place, N, v);
        } else {
            return;
        }
    }
}

int main() {
    ll N;
    cin >> N;

    vector<ll> v;
    dfs(0, N, v);

    int ans = 0;
    for (int n : v) {
        bool has3 = false, has5 = false, has7 = false;
        while (n) {
            if (n % 10 == 3) {
                has3 = true;
            } else if (n % 10 == 5) {
                has5 = true;
            } else if (n % 10 == 7) {
                has7 = true;
            }

            n /= 10;
        }
        if (has3 && has5 && has7) ans++;
    }

    cout << ans << endl;
}