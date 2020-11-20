#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for (int n = 0; n <= N; n++) {
        for (int m = 0; m <= M; m++) 
            if (K == m * N + n * M - 2 * m * n) {
                cout << "Yes" << endl;
                return 0;
            }
    }
    cout << "No" << endl;
}
