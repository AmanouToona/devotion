#include <bits/stdc++.h>
using namespace std;

const float PI = acos(-1);

int main() {
    float oa, ab, bc;
    cin >> oa >> ab >> bc;

    float ans = 0;
    ans += (oa + ab + bc) * (oa + ab + bc) * PI;

    float oc;
    if (oa >= ab + bc) {
        oc = oa -ab - bc;
    } else if (ab >= oa + bc) {
        oc = ab - oa - bc;
    } else if (bc > oa + ab) {
        oc = bc - ab - oa;
    } else {
        oc = 0;
    }

    ans -= oc * oc * PI;
    cout << fixed << setprecision(6) << ans << endl;
}