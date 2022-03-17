#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string X;
    cin >> X;

    ll s = 0;
    for (char x : X) {
        s += x - '0';
    }

    string ans = "";
    ll carry = 0;
    for (int i = X.size() - 1;; i--) {
        carry += s;
        ans.push_back((carry % 10) + '0');

        carry /= 10;
        if (i >= 0) {
            s -= X[i] - '0';
        }
        if (carry == 0 && s == 0) {
            break;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}