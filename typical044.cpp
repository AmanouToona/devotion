#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll shift_sum = 1LL * N * Q;
    for (int i = 0; i < Q; i++) {
        ll  T, x, y;
        cin >> T >> x >> y;

        x--; y--;
        
        x = (x + shift_sum) % N;
        y = (y + shift_sum) % N;

        if (T == 1) {
            int temp = A[x];
            A[x] = A[y];
            A[y] = temp;
            continue;
        }

        if (T == 2) {
            shift_sum--;
            continue;
        }

        if (T == 3) {
            cout << A[x] << endl;
            continue;
        }
    }
}