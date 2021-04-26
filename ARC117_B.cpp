#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    A[N] = 0;
    ll ans = 1;

    sort(A.begin(), A.end());
    for (int i = 0; i < A.size() - 1; i++) {
        if (A[i + 1] == A[i]) continue;
        ans *= (A[i + 1] - A[i] + 1);
        ans %= MOD;
    }

    cout << ans << endl;


}


// 3
// 2 3 4