#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    int X, Y;

    cin >> N >> M;
    cin >> X >> Y;

    vector<pair<int, char>> t;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        t.push_back(make_pair(a, 'A'));
    }
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        t.push_back(make_pair(b, 'B'));
    }

    sort(t.begin(), t.end());

    int ans = 1;
    int start = 0;
    while (t[start].second != 'A') start++;

    int nxt = t[start].first + X;
    char now_port = 'B';
    for (int i = start; i < t.size(); i++) {
        if (t[i].first < nxt) continue;
        if (t[i].second != now_port) continue;

        ans++;
        if (now_port == 'A') {
            nxt = t[i].first + X;
            now_port = 'B';
        } else {
            nxt = t[i].first + Y;
            now_port = 'A';
        }
    }

    cout << ans / 2 << endl;

}