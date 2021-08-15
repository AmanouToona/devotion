#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1 << 19];

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cout << dp[0] <<endl;
    cout << dp[10] << endl;


}