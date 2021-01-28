#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, mod = pow(10, 9) + 7;
    cin >> N;

    vector<ll> num(N, 1);

    for (int i = 2; i <= N; i++) {
        int ii = i;
        int prime = 2;
        while(ii > prime) {
            if (ii % prime == 0) {
                num[prime - 1]++;
                ii /= prime;
            } else {
                prime++;
            }
        }

        num[ii - 1]++;
    }

    ll ans = 1;
    for (int i = 0; i < N; i++) {
        if (i == 0) continue;
        ans *= num[i];
        ans %= mod;
    }

    cout << ans << endl;

}