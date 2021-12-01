#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll sum_seq(ll a, ll b) {
    ll res = (a + b) * (a - b + 1) / 2;
    return res;
}


int main() {
    int N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.rbegin(), A.rend());
    A.push_back(0);

    ll ans = 0LL;
    int i = 0;
    while(i < N) {
        while (i < N && A[i] == A[i + 1]) i++;

        ll diff = A[i] - A[i + 1];
        if (diff * (i + 1) <= K) {
            K -= diff * (i + 1);

            ans += sum_seq(A[i], A[i + 1] + 1) * (i + 1);
            if (K <= 0) break;
            i++;
            continue;
            }

        int ride = K / (i + 1);
        int rem = K % (i + 1);
        ans += sum_seq(A[i], A[i] - ride + 1) * (i + 1);
        ans += rem * (A[i] - ride);

        break;
    }

    cout << ans << endl;
}
