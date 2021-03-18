#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool win(vector<int> S, vector<int> T){
    vector<int> count(9, 0);
    for (auto s: S) {
        count[s - 1]++;
    }
    int score_s = 0;
    for (int i = 0; i < 9; i++) {
        score_s += (i + 1) * pow(10, count[i]);
    }

    vector<int> count_t(9, 0);
    for (auto t: T) {
        count_t[t - 1]++;
    }
    int score_t = 0;
    for (int i = 0; i < 9; i++) {
        score_t += (i + 1) * pow(10, count_t[i]);
    }

    return score_s > score_t;
}


int main() {
    int K;
    string S, T;
    cin >> K;
    cin >> S >> T;

    vector <int> si, ti;
    for (auto s: S) {
        if (s == '#') break;
        si.push_back(s - '0');
    }
    for (auto t: T) {
        if (t == '#') break;
        ti.push_back(t - '0');
    }
    
    vector<int> tot_num(9, K);
    for (auto s: si) {
        tot_num[s - 1]--;
    }
    for (auto t: ti) {
        tot_num[t - 1]--;
    }

    ll win_case = 0, lose_case = 0;
    for (int s = 1; s <= 9; s++) {
        for (int t = 1; t <= 9; t++) {
            si.push_back(s);
            ti.push_back(t);

            ll num_case = 0;
            if (s == t) {
                num_case = 1LL * tot_num[s - 1] * (tot_num[s - 1] - 1);
            } else {
                num_case = 1LL *tot_num[s - 1] * tot_num[t - 1];
            }

            if (win(si, ti) == true) {win_case += num_case;} 
            else {lose_case += num_case;}
            si.pop_back();
            ti.pop_back();            
        }
    }
    double ans = win_case * 1.0L / (win_case + lose_case);

    printf("%f7\n", ans);

}

/*
100000
9299#
6266#
0.9012487
*/
