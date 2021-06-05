#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x1, y1, r, x2, y2, x3, y3;
    cin >> x1 >> y1 >> r;
    cin >> x2 >> y2 >> x3 >> y3;

    bool red=false, blue = false;
    for (int x = -200; x <= 200; x++){
        for (int y = -200; y <= 200; y++) {
            if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= r * r && ((x < x2 || x > x3) || (y < y2 || y > y3))) {
                red = true;
            }
            if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) > r * r && (x2 <= x  && x <= x3 && y2 <= y && y <= y3)) {
                blue = true;
            }
        }
    }

    if (red) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    if (blue) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}