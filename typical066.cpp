#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            int cnt = 0, all = 0;
            for (int k = L[i]; k <= R[i]; k++) {
                for (int l = L[j]; l <= R[j]; l++) {
                    all++;
                    if (k > l) cnt++;
                }
            }
            ans += (double)cnt / all;
        }
    }


    cout.precision(15);
    cout << fixed << ans << endl;
}
