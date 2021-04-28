#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll A;
    double B;
    cin >> A >> B;

    ll iB = B * 100 + 0.5;

    A *= iB;
    A /= 100;


    printf("%lld\n", A);
}