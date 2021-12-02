#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    int r = 0;
    for (int i = 0; i < N; i++) {
        while (r <= i || (r < N && A[r] > A[r - 1])) r++;
        if (r - i >= K) ans++;
    }

    cout << ans << endl;
}