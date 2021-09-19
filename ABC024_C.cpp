#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, D, K;
    cin >> N >> D >> K;

    vector<pair<int, int>> LR;
    for (int i = 0; i < D; i++) {
        int L, R;
        cin >> L >> R;
        LR.push_back(make_pair(L, R));
    }

    for (int i = 0; i < K; i++) {
        int S, T;
        cin >> S >> T;

        int day = 0;
        int now = S;
        bool direction_plus = T > S;  // 大きい方へ移動するのか？
        while(true) {
            if (direction_plus && LR[day].first <= now && LR[day].second > now) {
                now = LR[day].second;
                if (now >= T) {
                    cout << day + 1 << endl;
                    break;
                }
            }

            if (!direction_plus && LR[day].second >= now && LR[day].first < now) {
                now = LR[day].first;
                if (now <= T) {
                    cout << day + 1 << endl;
                    break;
                }
            }
            day++;
        }
    }
}
