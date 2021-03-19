#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<int, int>> baggage, X;

    for(int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        baggage.push_back(make_pair(v, w));
    }

    for(int i = 0; i < M; i++) {
        int x;
        cin >> x;
        X.push_back(make_pair(x, i));
    }
    sort(baggage.begin(), baggage.end(), greater<pair<int, int>>());
    sort(X.begin(), X.end());

    for(int q = 0; q < Q; q++){
        int L, R, ans = 0;
        cin >> L >> R;
        --L;
        --R;
    
        vector<bool> empty(M, true);
        for(int n = 0; n < N; n++){ 
            for(int m = 0; m < M; m++) {
                if(L <= X[m].second && X[m].second <= R) continue;
                if(! empty[m]) continue;
                
                if(X[m].first >= baggage[n].second) {
                    ans += baggage[n].first;
                    empty[m] = false;
                    break;
                }

            }
        }
        cout << ans << endl;
    }

}