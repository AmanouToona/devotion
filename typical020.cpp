#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll powll(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if (b & 1) {
            res *= a;
        }
        a *= a;

        b >>= 1;
    }

    return res;
}


int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    if (a < powll(c, b)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}