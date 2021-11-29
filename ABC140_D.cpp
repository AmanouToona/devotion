#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    int group = 1;
    for (int i = 1; i < N; i++) {
        if (S[i - 1] != S[i]) group++;
    }

    group = max(1, group -  2 * K);
    cout << N - group << endl;

}