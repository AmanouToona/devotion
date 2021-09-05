#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);

    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    vector<ll> diff(N - 1);
    for (int i = 0; i < N - 1; i++) {
        diff[i] = A[i + 1] - A[i];
        ans += abs(diff[i]);
    }

    for (int i = 0; i < Q; i++) {
        int L, R, V;
        cin >> L >> R >> V;
        L--; R--;

        if (L - 1 >= 0) {
            ans += abs(diff[L - 1] + V) - abs(diff[L - 1]);
            diff[L - 1] += V;
        }
        if (R < N - 1) {
            ans += abs(diff[R] - V) - abs(diff[R]);
            diff[R] -= V;
        }

        cout << ans << endl;

    }
}
