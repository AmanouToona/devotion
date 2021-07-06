#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);

    for (int i = 0; i < N; i++) cin >> A[i];

    map<int, int> m;
    m[A[0]] += 1;
    int left = 0, right = 1, ans = 0;
    while(right <= N) {
        if (m.size() > K) {
            m[A[left]] -= 1;
            if (m[A[left]] == 0) {
                m.erase(A[left]);
            }
            left++;
            continue;
        }

        ans = max(ans, right - left);
        if (right >= N) break;
        m[A[right]]++;
        right++;

    }

    cout << ans << endl;

}