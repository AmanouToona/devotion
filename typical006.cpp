#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    string ans = "";
    int left = -1;
    for (int n = 0; n < K; n++) {  // 答えのn文字目の探索
        int min_alphabet = 30;
        for (int i = left + 1; i < N - (K - 1 - n); i++) {
            if (S[i] - 'a' < min_alphabet) {
                left = i;
                min_alphabet = S[i] - 'a';
            }
        }
        ans.push_back(S[left]);
    }

    cout << ans << endl;

}