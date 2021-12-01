#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        m[a]++;
    }

    int dbl = 0;
    for (auto [key, value]: m) {
        if (value >= 2) {
            dbl += value - 1;
        }
    }

    int ans = N - (dbl + 1) / 2 * 2;
    cout << ans << endl;

}