#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> A(N + 1);
    int before = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = a - before;
        before = a;
    }
    A[N] = L - before;


    int left = 1, right = accumulate(A.begin(), A.end(), 0) + 1, mid;
    while (right - left > 1) {
        mid = (left + right) / 2;

        bool can = false;
        int count = 0, length = 0;
        for (auto a: A) {
            length += a;
            if (length >= mid) {
                count++;
                length = 0;
            }
        }

        if (count >= K + 1) can = true;
        if (can) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
