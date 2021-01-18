# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, mod=1000000007;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    sort(T.begin(), T.end());

    long long penalty=T[0], time=T[0], solve=1, streak=1, patern=1;

    for (int i = 1; i < N; i++) {
        penalty += T[i] + time;
        time += T[i];
        penalty;

        if (T[i] == T[i-1]) {
            streak += 1;
            patern *= streak;
            patern %= mod;
        } else {
            solve *= patern;
            solve %= mod;
            streak = 1;
            patern = 1;
        }

    }

    solve *= patern;
    solve %= mod;

    cout << penalty << endl;
    cout << solve << endl;
}