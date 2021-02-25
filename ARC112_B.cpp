#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll B, C;
    cin >> B >> C;

    if (C == 1) {
        cout << 2 << endl;
        return 0;
    }

    ll ans = 0;
    ll left1 = B - floor(C / 2);
    ll right1 = B + floor((C - 2) / 2);

    ll left2 = -B - floor((C - 1) / 2);
    ll right2 = -B + floor((C - 1) / 2);

    if (right2 < left1 || right1 < left2) {
        ans = right1 - left1 + 1 + right2 - left2 + 1;
    } else {
        ans = max<ll>(right1, right2) - min<ll>(left1, left2) + 1;
    }

    cout << ans << endl;

}
