#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    map<pair<int, int>, int> m;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (X[i] < X[j]) {
                m[make_pair(X[i] - X[j], Y[i] - Y[j])]++;
            } else if (X[i] != X[j]) {
                m[make_pair(X[j] - X[i], Y[j] - Y[i])]++;
            } else {
                if (Y[i] > Y[j]) {
                    m[make_pair(X[j] - X[i], Y[j] - Y[i])]++;
                } else {
                    m[make_pair(X[i] - X[j], Y[i] - Y[j])]++;
                }
            }
        }
    }

    int ans = 0;
    for (auto &[key, value] : m) {
        ans = max(ans, value);
    }
    ans = N - ans;
    cout << ans << endl;
}