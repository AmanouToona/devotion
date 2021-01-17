#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    map<char, char> dict1;
    map<char, char> dict2;
    for (int i = 0; i < S.size(); i++) {
        char s = S[i];
        char t = T[i];

        if (dict1.count(s) != 0) {
            if (dict1[s] != t) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            dict1[s] = t;
        }

        if (dict2.count(t) != 0) {
            if (dict2[t] != s) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            dict2[t] = s;
        }
    }
    cout << "Yes" << endl;
}
