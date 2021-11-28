#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        X[i] = (i + 1) - A[i];
        Y[i] = (i + 1) + A[i];
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll ans = 0LL;
    int l = 0, r = 0;
    for (int x: X) {
        while (l < N && Y[l] < x) l++;
        while (r < N && Y[r] <= x) r++;
        ans += r - l;
    }

    cout << ans << endl;
}