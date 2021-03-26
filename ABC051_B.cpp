#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int K, S;
    cin >> K >> S;

    ll ans = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            if (0 <= S - x - y && S - x - y <= K) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
