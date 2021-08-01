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

    int ans = 0, right = 0, left = 0;
    ll section_times = 1;
    for (int right = 0; right < N; right++) {
        section_times *= S[right];
        if (section_times <= K) {
            ans = max(ans, right - left + 1);
            continue;
        }

        while(left <= right && section_times > K) {
            section_times /= S[left];
            left++;
        }

    }

    cout << ans << endl;

}