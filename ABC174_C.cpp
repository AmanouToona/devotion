#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int K;
    cin >> K;

    int ans = -1;
    int u = 7 % K;
    if (u == 0) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; i <= K; i++) {
        u = u * 10 + 7;
        u %= K;
        if (u == 0) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

}