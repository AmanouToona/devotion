#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll A, ll B) {
    if (A < B) {
        ll C = A;
        A = B;
        B = C;
    }
    ll res = 0;
    if (A % B == 0) res = B;
    else res = gcd(B, A % B);
    return res;
}



int main () {
    ll A, B, C;
    cin >> A >> B >> C;

    ll gcd_ab = gcd(A, B);
    ll gcd_all = gcd(C, gcd_ab);

    ll ans = (A / gcd_all - 1) + (B / gcd_all - 1) + (C / gcd_all - 1);

    cout << ans << endl;

}