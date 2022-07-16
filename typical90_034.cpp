#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    map<int, int> m;
    int count = 0;
    int ans = 0;
    int l = 0, r = 0;
    for (l = 0; l < N; l++) {
        while (r < N && (count < K || (m.count(A[r]) != 0 && m[A[r]] != 0))) {
            int a = A[r];
            if (m.count(a) == 0 || m[a] == 0) {
                m[a] = 1;
                count++;
            } else {
                m[a]++;
            }
            r++;
        }
        ans = max(ans, r - l);

        m[A[l]]--;
        if (m[A[l]] == 0) {
            count--;
        }
    }
    cout << ans << endl;
}