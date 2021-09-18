#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned ll;

ull const MOD = 1e9 + 7;

ull pow(ull x, ull n) {
    ull res = 1;
    while (n > 0) {
        if (n & 1) res *= x;
        n >>= 1;
        x *= x;

        res %= MOD;
        x %= MOD;
    }
    return res;
}

ull div(ull a, ull b) {
    return (a * pow(b, (ull)(MOD - 2))) % MOD;
}


ull power10[22];
void init() {
    power10[0] = 1;
    for (int i = 1; i <= 19; i++) {
        power10[i] = power10[i - 1] * 10ull;
    }
}


ull f(ull x) {
    ull res = x % MOD;
    res *= (x + 1) % MOD;
    res %= MOD;
    res = div(res, 2ULL);
    return res;
}



int main() {
    ll L, R;
    cin >> L >> R;
    
    init();
    ull ans = 0;
    for (int i = 1; i <= 19; i++) {  // i: 桁数
        ull vl = max<ull>((ull)L, power10[i - 1]);
        ull vr = min<ull>((ull)R, power10[i] - 1ull);

        if (vl > vr) continue;

        ans += (f(vr) - f(vl - 1) + MOD) % MOD * 1ull * i;
        ans %= MOD;
    }

    cout << (ll)ans << endl;

}
