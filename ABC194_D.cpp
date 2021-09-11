#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    double ans = 0;

    for (double i = 1; i < N; i++) {
        ans += 1 / i;
    }

    ans *= N;

    cout.precision(15);
    cout << fixed << ans << endl;

}