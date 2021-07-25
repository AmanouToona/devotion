#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<ll> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i]; 
    for (int i = 0; i < N; i++) cin >> C[i]; 

    vector<ll> a(46, 0), b(46, 0), c(46, 0);
    for (int i = 0; i < N; i++ ) {
        a[A[i] % 46]++;
        b[B[i] % 46]++;
        c[C[i] % 46]++;
    }

    ll ans = 0;
    for (int i = 0; i < 46; i++) {
        for (int j = 0; j < 46; j++) {
            for (int k = 0; k < 46; k++) {
                if ((i + j + k) % 46 != 0) continue;
                ans += a[i] * b[j] * c[k];
            }
        }
    }

    cout << ans << endl;

}
