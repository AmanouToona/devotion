#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    ll Y;
    cin >> N >> Y;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N - i; j++) {
            if (Y == 1000 * (N - i - j) + 5000 * j + 10000 * i) {
                cout << i << " " << j << " " << N - i - j << endl;
                return 0;
            }
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;

}
