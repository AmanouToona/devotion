#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int M;
    cin >> M;

    vector<vector<bool>> cant(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cant[x][y] = true;
        cant[y][x] = true;
    }

    vector<int> member;
    for (int i = 0; i < N; i++) member.push_back(i);


    int ans = INT_MAX;
    do {
        // バトンの受け渡しができる場合のタイムの確認
        int _ans = 0;
        for (int i = 0; i < N; i++) {
            _ans += A[member[i]][i];
        }

        // バトンの受け渡しができるか確認
        bool can = true;
        for (int i = 0; i < N - 1; i++) {
            if (cant[member[i + 1]][member[i]]) can = false;
        }

        if (can) ans = min(ans, _ans);
    }
    while(next_permutation(member.begin(), member.end()));
    
    if (ans == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

}