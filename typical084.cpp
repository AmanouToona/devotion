#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    ll ans = 0;
    int right = 0; // [left, right]
    for (int left = 0; left < N; left++) {
        while(S[left] == S[right]) right++;
        if (right == left) break;
        ans += N - right;
    }
    cout << ans << endl;
}