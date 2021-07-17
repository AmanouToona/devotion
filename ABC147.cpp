#include<bits/stdc++.h>
using namespace std;
using ll = long long;


const int MOD = 1000000007;


int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 0; i <= 60; i++) {
        ll count_one = 0;
        for (ll a: A) {
            if ((a >> i) & 1) count_one++;
        }

        ll num = (1LL << i);
        num %= MOD;
        
        ans += num * count_one % MOD * (N - count_one) % MOD;
        ans %= MOD;

    }

    cout << ans << endl;

}

/*
10
3 14 159 2653 58979 323846 2643383 27950288 419716939 9375105820

*/
