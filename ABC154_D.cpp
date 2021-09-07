#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    vector<double> E(N);
    for (int i = 0; i < N; i++) {
        E[i] = (double)(P[i] + 1) / 2;
    }

    int right = 0;
    double cusum = 0;
    double ans = 0;
    for (int left = 0; left <= N - K; left++) {

        while (right < N && right - left < K) {
            cusum += E[right];
            right++;
        }

        ans = max(ans, cusum);
        cusum -= E[left];
    }

    cout.precision(15);
    cout << fixed << ans << endl;

}