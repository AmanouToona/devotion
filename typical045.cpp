#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e19;


void popmember(vector<int> &member, int bit) {
    for (int i = 0; i < 15; i++) {
        if ((bit >> i) & 1) member.push_back(i);
    }
}


int main() {
    int N, K;
    cin >> N >> K;

    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    // 先にグループ内の2点間最大距離を導出する
    vector<ll> dist(1 << N);
    for (int bit = 1; bit < (1 << N); bit++) {
        vector<int> member;
        popmember(member, bit);

        if (member.size() == 1) {
            dist[bit] = 0;
            continue;
        }

        if (member.size() == 2) {
            dist[bit] = (X[member[0]] - X[member[1]]) * (X[member[0]] - X[member[1]]);
            dist[bit] += (Y[member[0]] - Y[member[1]]) * (Y[member[0]] - Y[member[1]]);
            continue;
        }

        ll d = 0;
        int all_mem = 0;
        for (int i = 0; i < member.size() - 1; i++) {
            for (int j = i + 1; j < member.size(); j++) {
                int two_mem = 0;
                two_mem |= (1 << member[i]);
                two_mem |= (1 << member[j]);
                all_mem |= two_mem;

                d = max(d, dist[two_mem]);
            }
        }
        dist[all_mem] = d;
    }


    vector<vector<ll>> dp(K + 1, vector<ll>(1 << N, INF));
    dp[0][0] = 0;
    
    for (int c = 1; c <= K; c++) {
        for (int b = 1; b < (1 << N); b++) {
            for (int k = b; k != 0; k = (k - 1) & b) {
                dp[c][b] = min(dp[c][b], max(dp[c - 1][b - k], dist[k]));
            }
        }
    }

    cout << dp[K][(1 << N) - 1] << endl;


}