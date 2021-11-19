#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = INT_MAX;

int warshall(vector<vector<int>> &G, int x, int p) {
    int n = G.size();
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = G[i][j];
            if (dp[i][j] == -1) dp[i][j] = x;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dp[i][j] <= p) res++;
        }
    }

    return res;
}



int main() {
    string ng = "Infinity";

    int N, P, K;
    cin >> N >> P >> K;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }

    int x_max, x_min;

    // K 個以上となる最小の X を探す
    int left = -1, right = P + 1;
    while(right - left > 1) {
        int mid = (left + right) / 2;
        if (warshall(A, mid, P) > K) left = mid;
        else right = mid; 
    }
    x_min = right;

    // K 個以上となる最大の X を探す
    left = -1, right = P + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (warshall(A, mid, P) < K) right = mid;
        else left = mid;
    }
    x_max = left;

    if (x_min == P + 1) {
        cout << "Infinity" << endl;
    } else {
        cout << x_max - x_min + 1 << endl;
    }

}