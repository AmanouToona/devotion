#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int inv = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) inv++;
        }
        inv %= mod;
    }

    int smaller = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] < A[j]) smaller++;
        }
        smaller %= mod;
    }

    ll ans = 0;
    ans += (1LL * inv * K) % mod;
    ans += ((1LL * K * (K - 1) / 2 ) % mod ) * smaller;
    // ans = (1LL * inv * K) % mod + ((1LL * K * (K - 1) / 2) % mod) * smaller;
    ans %= mod;
    cout << ans << endl;
    
}
/*
10 2
10 9 8 7 5 6 3 4 2 1
131

*/
