#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int const MOD = 998244353;
 

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    ll min_sum = 0, ans = 0;
    for (auto a: A) {
        min_sum += a;

        ans = (ans + min_sum * a % MOD) % MOD;
        min_sum = (min_sum * 2 - a) % MOD;

    }

    cout << ans << endl;

}