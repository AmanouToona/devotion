#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    int N;
    cin >> N;
    vector<vector<int>> C(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> C[i][j];
        }
    }

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        B[i] = C[0][i];
    }
    for (int i = 0; i < N; i++) {
        A[i] = C[i][0] - B[0];
    }

    int minA = INT_MAX, minB = INT_MAX;
    for (int i = 0; i < N; i++) {
        minA = min(minA, A[i]);
        minB = min(minB, B[i]);
    }

    if (minA < 0) {
        for (int i = 0; i < N; i++) {
            A[i] -= minA;
            B[i] += minA;
        }
    }
    if (minB < 0) {
        for (int i = 0; i < N; i++) {
            A[i] += minB;
            B[i] -= minB;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (C[i][j] != A[i] + B[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (A[i] < 0 || B[i] < 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (auto a: A) {
        cout << a << " ";
    }
    cout << endl;

    for (auto b: B) {
        cout << b << " ";
    }
    cout << endl;


}