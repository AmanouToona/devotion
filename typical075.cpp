#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll N;
    cin >> N;

    int count_prime = 0;
    ll original_num = N;

    for (ll i = 2; i * i <= original_num; i++) {
        while(N % i == 0 && N != 1) {
            count_prime++;
            N /= i;
        }
    }
    if (N != 1) count_prime++;

    int ans = 0;
    while (1 << ans < count_prime) ans++;

    cout << ans << endl;
}
