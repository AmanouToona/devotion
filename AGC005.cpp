#include <bits/stdc++.h>
using namespace std;

int main() {
    string X;
    cin >> X;

    int del = 0;
    int s = 0;
    for (char x : X) {
        if (x == 'S') {
            s++;
            continue;
        }
        if (s > 0) {
            s--;
            del++;
        }
    }

    cout << X.size() - del * 2 << endl;
}