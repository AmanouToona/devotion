#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 1 << 30;
    for (int i = 0; i < (1 << N); i++) {
        int or_sum = 0, xor_sum = 0;
        for (int j = 0; j < N; j++) {
            or_sum = or_sum | A[j];

            if (j == N - 1) {
                xor_sum = xor_sum ^ or_sum;
                break;
            }

            if ((i >> j) & 1) {
                xor_sum = xor_sum ^ or_sum;
                or_sum = 0;
            }

        }
        ans = min(ans, xor_sum);
    }

    cout << ans << endl;

}