#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> b(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++) {
            b[i][j] = temp[j] - '0';
        }
    }

    vector<int> dx = {1, 0, -1, 0}, dy = {0, -1, 0, 1};

    vector<vector<int>> a(N, vector<int>(M, 0));
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            int am = 100;
            for (int k = 0; k < 4; k++) {
                am = min(am, b[i + dy[k]][j + dx[k]]);
            }
            for (int k = 0; k < 4; k++) {
                b[i + dy[k]][j + dx[k]] -= am;
            }
            a[i][j] = am;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}