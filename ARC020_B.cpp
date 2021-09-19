#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<int> odd(10, 0), even(10, 0);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even[A[i] - 1] ++;
        } else {
            odd[A[i] - 1] ++;
        }
    }

    int odd_max = max_element(odd.begin(), odd.end()) - odd.begin();
    int even_max = max_element(even.begin(), even.end()) - even.begin();

    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());

    int ans;
    if (odd_max != even_max) ans = n - odd[0] - even[0];
    else {
        ans = min(n - odd[0] - even[1], n - odd[1] - even[0]);
    }

    cout << ans * c << endl;

}