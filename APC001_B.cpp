#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    ll two_one = 0;
    ll one = 0;

    for (int i = 0; i < N; i++) {
        ll c = a[i] - b[i];
        if (c > 0) one += c;
        else two_one += c / 2;
    }

    if (two_one + one <= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}