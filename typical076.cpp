#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll sum_a = 0;
    for (int i = 0; i < N; i++) sum_a += 1LL * A[i];

    ll cusum = 0;
    int right = 0;
    for (int left = 0; left < N; left++) {
        while(cusum * 10 < sum_a) {
            cusum += A[right];
            right++;
            right %= N;
        }
        if (cusum * 10 == sum_a) {
            cout << "Yes" << endl;
            return 0;
        }
        cusum -= A[left];
    }

    cout << "No" << endl;
    return 0;
}