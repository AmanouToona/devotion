#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<string> S(N), T(N);
    vector<vector<char>> nxt(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    int ans = N * N;
    for (int i = 0; i < 4; i++) {
        int count = 0;
        count = min(i, 4 - i);

        // 色が異なる個数をカウント
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (S[row][col] != T[row][col]) count++;
            }
        }

        ans = min(ans, count);
        // 回転する
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                nxt[col][N - row - 1] = S[row][col];
            }
        }

        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                S[row][col] = nxt[row][col];
            }
        }

    }

    cout << ans << endl;
    return 0;

}
