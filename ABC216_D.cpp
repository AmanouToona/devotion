#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(M);
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    
}