#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    int ans=0, left=0, right=s.size() - 1;
    while(right - left > 0) {
        if (s[left] == s[right]) {
            left++; 
            right--;
            continue;
        }

        if (s[left] != 'x' and s[right] != 'x') {
            cout << -1 << endl;
            return 0;
        }

        if (s[left] == 'x') {
            ans++;
            left++;
            continue;
        }

        if (s[right] == 'x') {
            ans++;
            right--;
        }
    }

    cout << ans << endl;
}
