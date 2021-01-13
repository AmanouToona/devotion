#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    };

    long long sum_A = accumulate(A.begin(), A.end(), 0);

    vector<int> rain(N);
    long long odd_sum = 0;
    for (int i = 1; i < N; i = i + 2) {
        odd_sum += A[i];
    };

    rain[0] =  sum_A - 2 * odd_sum;

    for (int i = 1; i < N; i++) {
        rain[i] = 2 * A[i - 1] - rain[i - 1];
    };

    for (int i = 0; i < N; i++) {
        if (i != 0) {cout << " ";};
        cout << rain[i];
    }
    cout << endl;
}
