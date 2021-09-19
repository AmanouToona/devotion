#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int counter = 0;
void rev_gcd(ll a, ll b, int k) {

    if (counter == k) {
        cout << a << " " << b << endl;
        return;
    }
    counter ++;
    if (b == 0) {
        rev_gcd(2, 1, k);
        return;
    }
    rev_gcd(a + b, a, k);
}

int main() {
    int K;
    cin >> K;

    rev_gcd(1, 0, K);
    
}