#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;

    vector<int> sharp(N + 1, 0), dot(N + 1, 0);

    for (int i = 0; i < N; i++){
        if (S[i] == '#') {
            sharp[i + 1] = sharp[i] + 1;
        }
        else {
            sharp[i + 1] = sharp[i];
        }

        if (S[N - 1 - i] == '.') {
            dot[N - i - 1] = dot[N - i] + 1;
        }
        else {
            dot[N - i - 1] = dot[N - i];
        }
    }

    int ans = N;
    for (int i = 0; i < N + 1; i++) {
        ans = min(ans, sharp[i] + dot[i]);
    }

    cout << ans << endl;
}