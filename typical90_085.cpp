#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll K;
    cin >> K;

    ll count = 0;
    for (ll a = 1; a * a * a <= K; a++) {
        for (ll b = a; a * b * b <= K; b++) {
            if (K % (a * b) == 0) count++;
        }
    }
    cout << count << endl;
}