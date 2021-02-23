#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    int a=0, b=0, c=0;
    for (auto s: S) {
        if (s == 'a') ++a;
        else if (s == 'b') ++b;
        else ++c;
    }

    if (abs(a - b) > 1) {cout << "NO" << endl; return 0;}
    if (abs(a - c) > 1) {cout << "NO" << endl; return 0;}
    if (abs(b - c) > 1) {cout << "NO" << endl; return 0;}
    cout << "YES" << endl;
    return 0;
}