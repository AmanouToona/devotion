#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    map<ll, int> m;
    ll ans = 0;
    ll cusum = 0LL;
    m[0] = 1;
    for (int a: A) {
        cusum += a;
        m[cusum]++;
        ans += m[cusum] * 1LL - 1;
    }

    cout << ans << endl;
}