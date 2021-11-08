#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll const INF = INT_MAX;

int main() {
    int N;
    cin >> N;

    int X, Y;
    cin >> X >> Y;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(X + 1, vector<ll>(Y + 1, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int x = 0; x <= X; x++) {
            for (int y = 0; y <= Y; y++) {
                int nxt_x = min(X, x + A[i]);
                int nxt_y = min(Y, y + B[i]);

                dp[i + 1][x][y] = min<ll>(dp[i + 1][x][y], dp[i][x][y]);  // 弁当i を購入しない
                dp[i + 1][nxt_x][nxt_y] = min<ll>(dp[i + 1][nxt_x][nxt_y], dp[i][x][y] + 1);  // 弁当i を購入する
            }
        }
    }

    if (dp[N][X][Y] != INF) {
        cout << dp[N][X][Y] << endl;
    } else {
        cout << -1 << endl;
    }

}
