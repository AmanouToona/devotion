#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int total = 0;
    for (auto a: A) {
        total ^= a;
    }

    for (int i = 0; i < N; i++) {
        cout << (total ^ A[i]);
        if (i != N - 1) cout << " ";
    }
    cout << endl;
    
}