#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> W(N), V(N);
    vector<pair<int, int>> X;
    for(int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
    };

    for(int i = 0; i < M; i++) {
        int x;
        cin >> x;
        X.push_back(make_pair(x, i));
    }
    sort(X.begin(), X.end(), greater<pair<int, int>>());

    for(int i = 0; i < Q; i++) {
        int L, R, ans=0;
        cin >> L >> R;
        

    }


}