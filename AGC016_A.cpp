#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 100;
    for (int i = 0; i < 26; i++) {
        int single = i + 'a';
        
        int streak = 0, max_streak = 0;
        for (auto j: s) {
            if (j == single) {
                max_streak = max(max_streak, streak);
                streak = 0;
            } else {
                streak ++;
            }
        }
        max_streak = max(max_streak, streak);

        ans = min(ans, max_streak);
    }

    cout << ans << endl;
}