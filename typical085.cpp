#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll K;
    cin >> K;

    ll count = 0;
    for (ll b = 1; b * b <= K; b++) {
        if (K % b != 0) continue;
        for (ll a = 1; a <= b; a++) {
            if (K < a * b * b) break;
            if (K % (a * b) == 0) count++;
        }
    }

    cout << count << endl;
}