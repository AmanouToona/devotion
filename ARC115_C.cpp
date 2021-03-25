#include <bits/stdc++.h>
using namespace std;
using ll = long long;


// sieve
void sieve(int N, vector<int> &res) {
    //return vector of prime numbers
    vector<bool> prime(N + 1, true);

    for (int i = 2; i <= N; i++){
        if (prime[i]) res.push_back(i);

        int j = i * 2;
        while(j <= N) {
            prime[j] = false;
            j += i;
        }
    }
}



int main() {
    int N;
    cin >> N;

    vector<int> ans(N + 1, 1);
    vector<int> prime;
    sieve(N, prime);


    for (auto i: prime) {
        ll j = i;
        while(j <= N) {
            for (int k = j; k <= N; k+=j) {
                ans[k]++;
            }
            j *= i;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
}
