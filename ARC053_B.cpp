#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    vector<int> alp(26, 0);
    for (auto s: S) {
        alp[s - 'a']++;
    }

    int odd = 0;
    for (auto count: alp) {
        if (count % 2 == 1) odd++;
    }

    if (odd == 0) {
        cout << S.size() << endl;
        return 0;
    }

    int even = (S.size() - odd) / 2;
    int ans = floor(even / odd) * 2 + 1;
    cout << ans << endl;

}