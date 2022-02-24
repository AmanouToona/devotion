#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> C(10e6 + 1, 0);
    for (int a : A) {
        C[a]++;
    }

    bool pc = true;
    for (int i = 2; i < C.size(); i++) {
        int count = 0;
        for (int j = i; j < C.size(); j += i) {
            count += C[j];
        }
        if (count > 1) pc = false;
    }

    int sc = 0;
    for (int a : A) {
        sc = gcd(a, sc);
    }

    if (pc) {
        cout << "pairwise coprime " << endl;
    } else if (sc == 1) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }
}
