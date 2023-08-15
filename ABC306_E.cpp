#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N);
    multiset<int> s, t;

    ll ans = 0LL;

    auto add = [&](int x) {
        s.insert(x);
        ans += x;

        int y = *s.begin();
        s.erase(s.find(y));
        ans -= y;

        t.insert(y);
    };

    auto del = [&](int x) {
        if (s.find(x) != s.end()) {
            s.erase(s.find(x));
            ans -= x;

            int y = *t.rbegin();
            s.insert(y);
            t.erase(t.find(y));
            ans += y;
        } else {
            t.erase(t.find(x));
        }
    };

    for (int i = 0; i < K; i++) s.insert(0);
    for (int i = K; i < N; i++) t.insert(0);

    int x, y;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        x--;

        add(y);
        del(A[x]);

        cout << ans << '\n';

        A[x] = y;
    }
}