#include<bits/stdc++.h>
using namespace std;
using ll = long long;

using vs = vector<string>;

vector<int> di = {1, 0, -1, 0};
vector<int> dj = {0, -1, 0, 1};

int ans = 0;
set<vector<string>> used;


void dfs(vector<string> &S, int num) {  // num: rest number to paint red.
    if (used.count(S)) return;
    used.insert(S);

    if (num == 0) {
        ans++;
        return;
    }

    int N = S.size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] != '@') continue;

            for (int k = 0; k < 4; k++) {
                int vi = i + di[k];
                int vj = j + dj[k];

                if (vi < 0 || vi >= N) continue;
                if (vj < 0 || vj >= N) continue;
                if (S[vi][vj] != '.') continue;

                S[vi][vj] = '@';
                dfs(S, num - 1);
                S[vi][vj] = '.';
            }
        }
    }
};






int main() {
    int N, K;
    cin >> N >> K;

    vs S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == '#') continue;
            S[i][j] = '@';
            dfs(S, K - 1);
            S[i][j] = '.';
        }
    }
    cout << ans << endl;
}
