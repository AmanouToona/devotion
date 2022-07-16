#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int x = X[N / 2];
    int y = Y[N / 2];

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(X[i] - x);
        ans += abs(Y[i] - y);
    }
    cout << ans << endl;
}