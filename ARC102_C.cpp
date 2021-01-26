#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<ll> num(K, 0);

    for (int i = 1; i <= N; i++) {
        num[i % K]++;
    }

    ll ans = 0;
    for (int a = 0; a < K; a++) {
        int b = (K - a) % K;
        int c = (K - a) % K;

        if ((b + c) % K == 0) {
            ans += num[a] * num[b] * num[c]; 
        }
    }

    cout << ans << endl;

}