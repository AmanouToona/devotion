#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, mod=pow(10, 9) + 7;
    string S;
    cin >> N;
    cin >> S;

    vector<int> bucket(26, 1);
    for (auto s: S) {
        bucket[s - 'a'] += 1;
    }

    long long ans = 1;
    for (auto b: bucket) {
        ans *= b;
        ans %= mod;
    }

    cout << ans - 1<< endl;

}