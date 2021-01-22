#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 100;
    for (int i = 0; i < 26; i++) {
        int single = i + 'a';

        int max_streak = 0;
        for (int j = 0; j < s.size(); j++) {
            
            int jj = j;
            while(j < s.size() && s[j] != i + 'a') j++;
            max_streak = max(max_streak, j - jj);

        }

        ans = min(ans, max_streak);
    }
    cout << ans << endl;
}