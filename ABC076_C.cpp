#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;

    cin >> S >> T;

    bool ans_flag = false;
    int ans_left=0;
    for (int left = S.size() - T.size(); left >= 0; left--) {
        for (int i = 0; i < T.size(); i++) {
            if (S.at(left + i) != T.at(i) && S.at(left + i) != '?') {
                break;
            }
            if (i == T.size() - 1) {
                ans_flag = true;
                ans_left = left;
            }
        }
        if (ans_flag) {
            break;
        }
    } 

    if (ans_flag) {
        for (int i = 0; i < S.size(); i++) {
            if (i >= ans_left && i <ans_left + T.size()) {
                S.at(i) = T.at(i - ans_left);
            }
            else if (S.at(i) == '?') {
                S.at(i) = 'a';
            }
        }
        cout << S << endl;
    }
    else {
        cout << "UNRESTORABLE" << endl;
    }
}
