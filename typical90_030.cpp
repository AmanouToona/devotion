#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void eratosthenes(vector<int>& prime, int n) {
    vector<int> isPrime(n + 1, true);
    isPrime[0] = false, isPrime[1] = false;

    for (int i = 0; i < n; i++) {
        if (!isPrime[i]) continue;

        prime.push_back(i);

        for (int j = i * 2; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
    return;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> prime;
    eratosthenes(prime, N);

    vector<int> count_p(N + 1, 0);
    for (int p : prime) {
        for (int q = p; q <= N; q += p) {
            count_p[q]++;
        }
    }

    int ans = 0;
    for (int a : count_p) {
        if (a >= K) ans++;
    }
    cout << ans << endl;
}
