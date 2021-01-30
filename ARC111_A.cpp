#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll modPow(ll a, ll b, ll mod) {
    if (b == 0) {return 1;};
    if (b == 1) {return a % mod;};
    if (b == 2) {return a * a % mod;};

    ll res = modPow(modPow(a, b / 2, mod), 2, mod) * modPow(a, b % 2, mod);
    res %= mod;
    return res;
}


int main() {
    ll N, M;
    cin >> N >> M;

    cout << modPow(10, N, M * M) / M << endl; 

    return 0;
}
