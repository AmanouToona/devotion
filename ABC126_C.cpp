#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    long double ans = 0;
    long double proba = 1 / (1.0 * N);
    ll coin_times = 1;

    for (int dice = N; dice >= 1; dice--) {
        int point = dice;
        while(point * coin_times < K) {
            proba *= 0.5;
            coin_times *= 2;
        }
        ans += proba;
    }
    cout << fixed << setprecision(11) << ans << endl;
}

