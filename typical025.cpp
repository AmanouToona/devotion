#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll solver(string N, string B, string now) {
    ll res = 0;
    if (N.size() == now.size()) {
        ll cumpos = 1;
        for (int i = 0; i < N.size(); i++) {
            if (now[i] == '0') continue;
            cumpos *= now[i] - '0';
        }

        { // m に 0 が含まれない場合
            ll m = stoll(B) + cumpos;
            if (m > stoll(N)) res += 0;
            else {
                bool flag = true;
                string M = to_string(m);
                for (int i = 0; i < M.size(); i++) {
                    if (M[i] == '0') flag = false; 
                }
                while(M.size() < N.size()) M.push_back('0');
                sort(M.begin(), M.end());
                sort(now.begin(), now.end());
                if (M == now && flag) res++;
            }
        }
        
        { // m に 0 が含まれる場合
            if (now[0] != '0') return res;
            ll m = stoll(B);
            if (m > stoll(N)) res+= 0;
            else {
                string M = to_string(m);
                bool flag = false;
                for (auto M_char: M) {if (M_char == '0') flag = true;}
                while(M.size() < N.size()) M.push_back('0');
                sort(M.begin(), M.end());
                sort(now.begin(), now.end());
                if (M == now && flag) {
                    res++;
                }
            }
        }
        return res;
    }

    int start = 0;
    if (now.size() != 0) start = now[now.size() - 1] - '0';
    for (int i = start; i < 10; i++) {
        now.push_back(i + '0');
        res += solver(N, B, now);
        now.pop_back();
    }

    return res;

}

// string 大文字  ll 小文字


int main() {
    string N, B, now;
    cin >> N >> B;


    ll ans = solver(N, B, now);

    cout << ans << endl;

}

/*
999 434
*/

