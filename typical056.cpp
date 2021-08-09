#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<string> ans(S + 1, "Impossible");
    ans[0] = "";
    for (int i = 0; i < N; i++) {
        for (int s = S; s >= 0; s--) {
            int u = s - A[i];
            if (u >= 0 && ans[u] != "Impossible" && ans[u].size() == i) {
                ans[s] = ans[u] + 'A';
                continue;
            }

            u = s - B[i];
            if (u >= 0 && ans[u] != "Impossible" && ans[u].size() == i) {
                ans[s] = ans[u] + 'B';
            }
        }
    }

    cout << ans.back() << endl;

}
