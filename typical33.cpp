#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    if (H == 1 || W == 1) {
        cout << H * W << endl;
        return 0;
    }

    int h = (H + 1) / 2;
    int w = (W + 1) / 2;
    int ans = h * w;
    cout << ans << endl;

    return 0;
}