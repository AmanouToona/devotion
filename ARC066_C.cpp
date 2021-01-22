#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, mod=1000000007;
    cin >> N;
    vector<int> A((N + 1) / 2);
    if (N % 2 == 1) {
        A[0] += 1;
    }

    for (int i=0; i<N; i++) {
        int ai;
        cin >> ai;
        A[ai / 2] += 1;
    }

    for (auto a: A) {
        if (a != 2) {
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = 1;
    for (int i = 0; i < A.size(); i++) {
        if (N % 2 == 1 && i == 0) continue;
        ans *= 2;
        ans %= mod;
    }

    cout << ans << endl;

}