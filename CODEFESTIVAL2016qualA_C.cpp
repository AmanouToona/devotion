#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    int K;
    cin >> K;

    vector<int> ans(s.size());
    for (int i = 0; i < s.size(); i++) {
        ans[i] = s[i] - 'a';
    }

    for (int i = 0; i < s.size(); i++) {
        int operation_cnt = (26 - ans[i]) % 26;

        if (operation_cnt <= K) {
            ans[i] = (ans[i] + operation_cnt) % 26;
            K -= operation_cnt;
        }
    }

    ans[ans.size() - 1] += K;
    ans[ans.size() - 1] %= 26;

    for (int i = 0; i < ans.size(); i++) {
        char out = 'a';
        out += ans[i];
        cout << out;
    }

    cout << endl;

}