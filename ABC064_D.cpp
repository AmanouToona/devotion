#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int bra=0, left=0, right=0; 
    for (auto s: S) {
        if (s == '(') bra++;
        else bra--;

        if (bra < 0) {
            left++;
            bra ++;
        }
    }

    for (int i = 0; i < left; i++) {
        cout << '(';
    }
    cout << S;
    for (int i = 0; i < bra; i++) {
        cout << ')';
    }
    cout << endl;
}