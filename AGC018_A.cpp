#include <bits/stdc++.h>
using namespace std;

int INF = 1000000001;


int GCD(int x, int y) {
    if (y == 0) return x;
    return GCD(y, x % y);
}


int main() {
    string ok = "POSSIBLE", ng = "IMPOSSIBLE";
    int N, K;
    cin >> N >> K;

    int max_a = 0, g;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        max_a = max(a, max_a);
        g = GCD(a, g);
    }

    if (K <= max_a & K % g == 0) {
        cout << ok << endl;
    }
    else {
        cout << ng << endl;
    }
}