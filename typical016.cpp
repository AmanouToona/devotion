#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<ll> Coin(3);
    for (int i = 0; i < 3; i++) {
        cin >> Coin[i];
    }

    sort(Coin.rbegin(), Coin.rend());

    ll ans = INT_MAX;
    for (int i = 0; N >= Coin[0] * i; i++) {
        for (int j = 0; N >= Coin[0] * i + Coin[1] * j; j++) {
            ll remain = N - Coin[0] * i - Coin[1] * j;
            if (remain == 0 || remain % Coin[2] == 0) {
                ans = min<ll>(ans, i + j + remain / Coin[2]);
            }
        }
    }

    cout << ans << endl;

}