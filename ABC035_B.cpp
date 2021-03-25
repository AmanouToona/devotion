#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int T;
    cin >> T;

    int x = 0, y = 0, q = 0;
    for (auto s: S) {
        if (s == 'L') x--;
        else if (s == 'R') x++;
        else if (s == 'U') y++;
        else if (s == 'D') y--;
        else q++;
    }

    if (T == 1) {
        cout << abs(x) + abs(y) + q << endl;
        return 0;
    }

    if(q <= abs(x) + abs(y)) {
        cout << abs(x) + abs(y) - q << endl;
    } else if ((q - abs(x) - abs(y)) % 2 == 1) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;

}