#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<bool> is_prime(N, true);
    is_prime[0] = false;

    for (int i = 1; i <= N; i++) {
        if (!is_prime[i - 1]) continue;
        int j = i + i;
        while (j <= N) {
            is_prime[j - 1] = false;
            j += i;
        }
    }

    vector<int> prime_factors(N, 0);
    for (int i = 1; i <= N; i++) {
        if (!is_prime[i - 1]) continue;

        int j = i;
        while (j <= N){
            prime_factors[j - 1]++;
            j += i;
        }
    }

    int ans = 0;
    for (int cnt: prime_factors) {
        if (cnt >= K) ans++;
    }

    cout << ans << endl;
}
