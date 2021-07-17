#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    int N;
    cin >> N;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans -= A[i] * (N - 1 - i);
        ans += A[i] * i;
    }

    cout << ans << endl;

}