#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string X;
    cin >> X;

    vector<ll> N(X.size());
    for (int i = 0; i < X.size(); i++) {
        for (int j = 0; j <= i; j++) {
            N[i - j] += X[j] - '0';
        }
    }

    ll carry = 0;
    for (int i = 0; i < N.size(); i++) {
        ll n = N[i];
        N[i] = n % 10;

        carry = n / 10;
        N[i + 1] += carry;
    }

    if (carry) cout << carry;
    for (int i = N.size() - 1; i >= 0; i--) {
        cout << N[i];
    }

    cout << endl;
}