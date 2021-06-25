#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(A[i] - B[i]);
    }

    if (ans > K) {
        cout << "No" << endl;
        return 0;
    }

    if (ans % 2 == K % 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
