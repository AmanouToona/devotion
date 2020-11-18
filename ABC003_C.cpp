#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> R;
    for (int i = 0; i < N; i++) {
        int r;
        cin >> r;
        R.push_back(r);
    }

    sort(R.begin(), R.end());

    float ans = 0;
    for (int i = N - K; i < N; i++) {
        ans = (ans + R[i]) / 2;
    }
    printf("%.6f", ans);
}
