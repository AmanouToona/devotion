#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) cin >> A[i] >> B[i];

    int K;
    cin >> K;
    vector<int> C(K), D(K);
    for (int i = 0; i < K; i++) cin >> C[i] >> D[i];

    int ans = 0;
    for (int i = 0; i < (1 << K); i++) {
        vector<bool> dish(N, false);
        for (int j = 0; j < K; j++) {
            if ((i >> j) & 1) {
                dish[C[j]] = true;
            } else {
                dish[D[j]] = true;
            }
        }

        int now_ans = 0;
        for (int m = 0; m < M; m++) {
            if (dish[A[m]] && dish[B[m]]) {
                now_ans++;
            }
        }
        ans = max(ans, now_ans);
    }

    cout << ans << endl;

}