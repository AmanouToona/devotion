#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    int64_t a;
    cin >> N >> M;

    priority_queue<int64_t> A;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A.push(a);
    }

    for (int m = 0; m < M; m++) {
        a = A.top();
        A.pop();

        A.push(a / 2);
    }

    long long ans = 0;
    for (int n = 0; n < N; n++) {
        a = A.top();
        A.pop();
        ans += a;
    }
    cout << ans << endl;
}
