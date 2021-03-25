#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> res(1000001, -1);
const int mod = 10007;

int tribonacci (int n) {
    if (res[n] != -1) {return res[n];}

    res[n] = 0;
    res[n] += tribonacci(n - 1);
    res[n] %= mod;
    res[n] += tribonacci(n - 2);
    res[n] %= mod;
    res[n] += tribonacci(n - 3);
    res[n] %= mod;

    return res[n];

}


int main() {
    int n;
    cin >> n;

    res[1] = 0;
    res[2] = 0;
    res[3] = 1;

    cout << tribonacci(n) << endl;

}