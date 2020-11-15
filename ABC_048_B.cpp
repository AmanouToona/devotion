# include <bits/stdc++.h>
using namespace std;


int main() {
    long long a, b, x, left, right, ans;
    cin >> a >> b >> x;

    if (a % x == 0) {
        left = a;
    }
    else {
        left = (a / x + 1) * x;
    }

    if (b % x == 0) {
        right = b;
    }
    else {
        right = (b / x) * x;
    }

    if (left > right) {
        cout << 0 << endl;
        return 0;
    }

    cout << (right - left) / x + 1 << endl;
}
