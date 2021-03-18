#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    ll ans = 0;
    char now = 'X';
    for (int i = 1; i < S.size() -1; i++) {
        if (S[i] == now) ans--;
        if (S[i - 1] == S[i] && S[i] != S[i + 1] && S[i] != now){
            ans += S.size() - 1 - i;
            now = S[i];
        }
    }

    if (S[S.size() - 1] == now) ans--;

    cout << ans << endl;
}