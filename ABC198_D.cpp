#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<string> S(3);
    for (int i = 0; i < 3; i++) {
        cin >> S[i];
    }

    map<char, int> mp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < S[i].size(); j++) {
            char s = S[i][j];
            if (mp.count(s) == 0) {
                mp[s] = mp.size();
            }
        }
    }

    if (mp.size() > 10) {
        cout << " UNSOLVABLE " << endl;
        return 0;
    }

    vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    do {
        vector<string> s(3, "");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < S[i].size(); j++) {
                s[i].push_back(num[mp[S[i][j]]] + '0');
            }
        }

        if (s[0][0] == '0' || s[1][0] == '0' ||s[2][0] == '0') continue;

        if (stoll(s[0]) + stoll(s[1]) == stoll(s[2])) {
            for (int i = 0; i < 3; i++) {
                cout << s[i] << endl;
            }
            return 0;
        }
    } while(next_permutation(num.begin(), num.end()));

    cout << "UNSOLVABLE" << endl;
}   