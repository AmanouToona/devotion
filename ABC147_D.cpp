#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    
    vector<vector<pair<int, int>>> testimonys(N, vector<pair<int, int>>());
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        for (int j = 0; j < A; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            testimonys[i].push_back(make_pair(x, y));
        }
    }

    int n2 = 1 << N;
    int ans = 0;
    for (int i = 0; i < n2; i++) {
        bool can = true;

        for (int j = 0; j < N; j++) {
            if ((i >> j & 1) == 0) continue;
            for (auto [x, y]: testimonys[j]) {
                if (((i >> x) & 1) == y) continue;
                else {can = false; break;}
            }
            if (!can) break;
        }
        if (!can) continue;

        int honest = 0;
        for (int n = 0; n < N; n++) {
            if ((i >> n & 1) == 1) honest++;
        }
        ans = max(ans, honest);
    }
    cout << ans << endl;
}
