#include <bits/stdc++.h>
using namespace std;


bool solve (int N, int K, int now, vector<int> &A, vector<vector<int>> &T) {
    bool res = true;
    for (int k = 0; k < K; k++) {
        A.push_back(k);
        if (A.size() == N) {
            int ans = T[0][A[0]];
            for (int i = 1; i < A.size(); i++) {
                ans ^= T[i][A[i]];
            }
            if (ans == 0) return false;
        } else {
        res = res && solve(N, K, now++, A, T); 
        }
        if (res == false) return res;
        A.pop_back();

    }
    return res;
}


int main() {
    int N, K;
    cin >> N >> K;

    string ans = "Nothing";

    vector<vector<int>> T(N, vector<int>(K, 0));
    for (int n = 0; n < N; n++) {
        for (int k = 0; k < K; k++) {
            cin >> T[n][k];
        }
    }

    vector<int> A;
    if (solve(N, K, 0, A, T)) {
        cout << "Nothing" << endl;
    } else{
        cout << "Found" << endl;
    }

}
