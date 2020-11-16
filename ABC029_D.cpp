#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;

    cin >> N;

    vector<int> n;
    for (int i = 0; i < N.size(); i++) {
        n.push_back(N.at(i) - '0');
    }

    // dp [digit][lower][count 1]
    vector<vector<vector<long long>>> dp(11, vector<vector<long long>>(2, vector<long long>(11)));
    dp.at(0).at(0).at(0) = 1;

    for (int digit = 0; digit < N.size(); digit++) {
        for (int lower=0; lower < 2; lower++) {
            for (int count=0; count < 10; count++) {
                for (int i=0; i <= (lower ? 9 : n.at(digit)); i++) {
                    if (i == 1) dp.at(digit + 1).at(lower || i < n.at(digit)).at(count + 1) += dp.at(digit).at(lower).at(count);
                    if (i != 1) dp.at(digit + 1).at(lower || i < n.at(digit)).at(count) += dp.at(digit).at(lower).at(count);
                }
            }
        }
    }

    long long ans = 0;
    for (int i =1; i <= 10; i++) {
        ans += i * dp.at(N.size()).at(0).at(i) + i * dp.at(N.size()).at(1).at(i);
    }

    cout << ans << endl;
}
