#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    for (int s: S) {
        if (s == 0) {
            cout << N << endl;
            return 0;
        }
    }

    int ans = 0, right = 0;
    ll section_times = 1;
    for (int left = 0; left < N; left++) {
        while((right <= left) ||(right < N && section_times * S[right] <= K)) {
            section_times *= S[right];
            right++;

        }

        if (section_times <= K) {         
            ans = max(ans, right - left);
        }
        section_times /= S[left];
    }

    cout << ans << endl;

}