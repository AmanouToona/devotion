#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll const MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ll cube_times = 0;
        for (int j = 0; j < 6; j++) {
            int A;
            cin >> A;
            cube_times += A;
            cube_times %= MOD;
        }
        ans *= cube_times;
        ans %= MOD;
    }

    cout << ans << endl;
}