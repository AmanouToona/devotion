#include<bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> dict;
    dict['b'] = 1;
    dict['c'] = 1;
    dict['d'] = 2;
    dict['w'] = 2;
    dict['t'] = 3;
    dict['j'] = 3;
    dict['f'] = 4;
    dict['q'] = 4;
    dict['l'] = 5;
    dict['v'] = 5;
    dict['s'] = 6;
    dict['x'] = 6;
    dict['p'] = 7;
    dict['m'] = 7;
    dict['h'] = 8;
    dict['k'] = 8;
    dict['n'] = 9;
    dict['g'] = 9;
    dict['z'] = 0;
    dict['r'] = 0;

    int N;
    cin >> N;

    bool check = false;
    for (int n = 0; n < N; n++) {
        string S;
        cin >> S;

        bool first = true;
        for (char s: S) {
            if (isupper(s)) s = tolower(s);

            if (dict.count(s)) {
                if (check && first) {cout << " " ; }
                check = true;
                first = false;
                cout << dict[s];

                check = true;
            }
        }
    }
    cout << endl;
}
