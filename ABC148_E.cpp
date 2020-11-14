#include <bits/stdc++.h>
using namespace std;

long long g1(long long n, int p);
long long g2(long long n, int p);


long long g1 (long long n, int p) {
    if (n == 0) return 0;
    return n / p + g1(n/p , p);
}

long long g2(long long n , int p) {
    long long res = 0;
    if (n % 2 == 1) {
        return g1(n, p) - g2(n - 1, p);
    }
    res = g1(n / 2, p);
    if (p == 2) {
        res += n / 2;
    }
    return res;
}

int main() {
    long long N;
    
    cin >> N;

    long long ans;
    ans = min(g2(N, 2), g2(N, 5));

    cout << ans << endl;

}


