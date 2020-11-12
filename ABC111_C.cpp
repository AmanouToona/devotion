#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> even(100001, 0), odd(100001, 0);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        if (i % 2 == 0) {
            odd.at(v) += 1;
        }
        else {
            even.at(v) += 1;
        }
    }

    vector<int>::iterator even_max_itr, odd_max_itr;
    even_max_itr = find(even.begin(), even.end(), *max_element(even.begin(), even.end()));
    odd_max_itr = find(odd.begin(), odd.end(), *max_element(odd.begin(), odd.end()));

    int ans, even_max_idx, odd_max_idx;
    even_max_idx = distance(even.begin(), even_max_itr);
    odd_max_idx = distance(odd.begin(), odd_max_itr);

    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());

    if (even_max_idx == odd_max_idx) {
        ans = min(n - even.at(0) - odd.at(1), n - even.at(1) - odd.at(0));
    }
    else {
        ans = n - even.at(0) - even.at(0);
    }

    cout << ans << endl;
}
