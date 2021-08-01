#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ans += i;
    }

    cout << ans << endl;


}