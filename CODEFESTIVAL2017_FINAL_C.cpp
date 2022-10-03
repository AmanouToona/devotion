#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N >= 24) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        vector<int> time;
        time.push_back(0);

        for (int j = 0; j < N; j++) {
            if ((i >> j) & 1) {
                time.push_back(D[j]);
            } else {
                time.push_back(24 - D[j]);
            }
        }

        sort(time.begin(), time.end());
        int min_diff = 100;
        for (int j = 0; j < time.size(); j++) {
            int diff = abs(time[(j + 1) % (time.size())] - time[j]);
            diff = min(diff, 24 - diff);
            min_diff = min(min_diff, diff);
        }
        ans = max(ans, min_diff);
    }
    cout << ans << endl;
}