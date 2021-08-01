#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<char> S(N), T(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> T[i];

    vector<int> s_zero, t_zero;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') s_zero.push_back(i);
        if (T[i] == '0') t_zero.push_back(i);
    }

    if (s_zero.size() != t_zero.size()) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < s_zero.size(); i++) {
        if (s_zero[i] != t_zero[i]) ans++;
    }

    cout << ans << endl;

}

