#include<bits/stdc++.h>
using ll = long long;
using namespace std;


void calc_prime(int N, vector<int> &res) {
    vector<bool> prime(N + 1, true);

    for (int i = 2; i <= N; i++) {
        if (prime[i]) res.push_back(i);

        int ii = i * 2;
        while(ii <= N) {
            prime[ii] = false;
            ii += i;
        }
    } 
}


int main() {
    int N;
    cin >> N;

    vector<int> A(N + 1, 1), prime;
    calc_prime(N, prime);


    for (int i: prime) {
        ll j = i;
        while(j <= N) {
            for (int k = j; k <= N; k+= j) A[k]++;
            j *= i;
        }
    }
    

    
    for (int i = 1; i <= N; i++) {
        cout << A[i];
        if (i != N) cout << " ";
    }
    cout << endl;
}