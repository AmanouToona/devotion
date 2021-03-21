#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[21][2][2][2];  // digit smaller bigger appear


int main() {
    ll A, B;
    cin >> A >> B;

    string ast = to_string(A);
    string bst = to_string(B);

    int digita = ast.length();
    int digitb = bst.length();
    
    vector<int> a, b;
    for (int i = 0; i < digitb - digita; i++) {a.push_back(0);}
    for (int i = 0; i < digita; i++) {
        a.push_back(ast[i] - '0');
    }
    for (int i = 0; i < digitb; i++) {
        b.push_back(bst[i] - '0');
    }

    dp[0][0][0][0] = 1;

    for(int i = 0; i < digitb; i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int bigger = 0; bigger < 2; bigger++) {
                for (int j = 0; j < 2; j++) {
                    for (int x = (bigger ? 0: a[i]); x <= (smaller ? 9 : b[i]); x++) {
                        dp[i + 1][smaller || x < b[i]][bigger || x > a[i]][j || (x == 4 || x == 9)] += dp[i][smaller][bigger][j];
                    }
                }
            }
        }
    }

    ll ans = dp[digitb][0][0][1] + dp[digitb][0][1][1] + dp[digitb][1][0][1] + dp[digitb][1][1][1];

    cout << ans << endl;

}
