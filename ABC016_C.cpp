#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b; a--; b--;

        A[a][b] = 1;
        A[b][a] = 1;
    }

    for (int i = 0; i < N; i++) {
        vector<int> ans(N, 0);

        for (int j = 0; j < N; j++) {
            if (A.at(i).at(j) == 0) continue;

            for (int k = 0; k < N; k++) {
                if (A.at(j).at(k) == 1)
                    ans.at(k) = 1;
            }

        }

        ans[i] = 0;
        for (int j = 0; j < N; j++) {
            if (A.at(i).at(j) == 1)
            ans.at(j) = 0;
        }

        cout << accumulate(ans.begin(), ans.end(), 0) << endl;
    }
}
