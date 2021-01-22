#include<bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> t;

bool solve (int n, int value) {
    if (n == N) return (value == 0);

    for (int k = 0; k < K; k++) {
        if (solve(n + 1, value^t[n][k])) return true;
    }
    return false;
}


int main() {
    cin >> N >> K;
    t.resize(N, vector<int>(K));

    for (int n = 0; n < N; n++) {
        for (int k = 0; k < K; k++) {
            cin >> t[n][k];
        }
    }

    if (solve(0, 0)) {
        cout << "Found" << endl;
    } else {
        cout << "Nothing" << endl;
    }
    return 0;
}
