#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> red(N, false);
    red[0] = true;

    vector<int> balls(N, 1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (red[x]) red[y] = true;

        balls[x]--;
        balls[y]++;

        if (balls[x] == 0) red[x] = false;
    }

    int ans = 0;
    for (auto tf: red) {
        if (tf) ans++;
    }
    cout << ans << endl;
}