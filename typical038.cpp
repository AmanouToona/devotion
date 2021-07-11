#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow18 = 1000000000000000000;


ll gcd(ll A, ll B) {
    if (A % B == 0) return B;

    return gcd(B, A % B); 
}


int main() {
    ll A, B;
    cin >> A >> B;

    ll g = gcd(A, B);

    ll ans = A;
    ans /= g;
    if (ans > pow18 / B) {
        cout << "Large" << endl;
        return 0;
    }

    ans *= B;
    cout << ans << endl;

}