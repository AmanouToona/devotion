#include <bits/stdc++.h>
using namespace std;

int main() {
     int N, K, M, R;
     cin >> N >> K >> M >> R;

    vector<int> S;
    for (int i = 0; i < N - 1; i++) {
        int s;
        cin >> s;
        S.push_back(s);
    }

    sort(S.begin(), S.end(), greater<int>());
    long long sum = 0;
    for (int k = 0; k < K - 1; k++) {
        sum += S.at(k);
    }

    long long ans;
    ans = (long long)R * (long long)K - sum;
    ans = ceil(ans);

    if (ans < 0) ans = 0;
    if (N - 2 >= K - 1 && S.at(K - 1) >= ans) ans = 0;
    if (ans > M) ans = -1;

    cout << ans << endl;
}
