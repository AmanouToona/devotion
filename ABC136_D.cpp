#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() { 
    string S;
    cin >> S;

    int left=0, right=0;
    vector<int> ans(S.size(), 0);

    while(1) {
        if (right == S.size() - 1) {
            ans[left] += (right - left + 2) / 2;
            ans[left - 1] += (right - left + 1) / 2;
            break;
        }
        if (S[right + 1] != S[right]){
            if (S[right] == 'R') {
                ans[right] += (right - left + 2) / 2;
                ans[right + 1] += (right - left + 1) / 2;
            } else {
                ans[left] += (right - left + 2) / 2;
                ans[left - 1] += (right - left + 1) / 2;
            }
            right++;
            left = right;
            continue;
        }

        right++;
    }

    for (int i = 0; i < S.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

}