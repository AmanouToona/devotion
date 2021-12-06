#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> used(*max_element(A.begin(), A.end()) + 2, 0);
    for (int i = 0; i < M; i++) {
        used[A[i]] ++;
    }

    int ans = INT_MAX;
    for (int i = 0; i < used.size(); i++) {
        if (used[i] == 0) {
            ans = min(ans, i);
        }
    }

    for (int i = M; i < N; i++) {
        used[A[i]]++;
        used[A[i - M]]--;
        if (used[A[i - M]] == 0) {
            ans = min(ans, A[i - M]);
        }
    }

    cout << ans << endl;
}
