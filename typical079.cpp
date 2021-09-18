#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int b; 
            cin >> b;

            A[i][j] = b - A[i][j];

        }
    }

    ll count_op = 0;
    for (int i = 0; i < H - 1; i++) {
        for (int j = 0; j < W - 1; j++) {
            count_op += abs(A[i][j]);
            A[i][j + 1] -= A[i][j];
            A[i + 1][j] -= A[i][j];
            A[i + 1][j + 1] -= A[i][j];
            A[i][j] = 0;
        }
        if (A[i][W - 1] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int j = 0; j < W; j++) {
        if (A[H - 1][j] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << count_op << endl;

}