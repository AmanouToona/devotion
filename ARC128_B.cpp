#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const INF = INT_MAX;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        vector<int> ball(3);
        cin >> ball[0] >> ball[1] >> ball[2];

        int ans = INF;
        for (int i = 0; i < 3; i++) {
            int operation = 0;
            operation += min(ball[(1 + i) % 3], ball[(2 + i) % 3]);
            
            int rest = max(ball[(1 + i) % 3], ball[(2 + i) % 3]) - min(ball[(1 + i) % 3], ball[(2 + i) % 3]);
            if (rest % 3 != 0) continue;
            
            operation += rest;

            ans = min(ans, operation);
        }

        if (ans == INF) {cout << -1 << endl;}
        else {cout << ans << endl;}
    }
}