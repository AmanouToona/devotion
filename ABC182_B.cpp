#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, ans, max_GCD = 0;
    cin >> N;

    vector<int> A(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 2; i <= 1000; i++) {
        int count = 0;

        for (int a: A) {
            if (a % i == 0) count++;
        }

        if (count > max_GCD) {
            max_GCD = count;
            ans = i;
        }
    }

    cout << ans << endl;
}