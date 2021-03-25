#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> salary(20, 0);
vector<vector<int>> subordinate(20);

ll dfs(int n) {
    if (salary[n] != 0) return salary[n];

    if (subordinate[n].empty()) {
        salary[n] = 1;
        return 1;
    }


    ll min_salary = LLONG_MAX, max_salary = 1;

    for (auto sub: subordinate[n]) {
        min_salary = min<ll>(min_salary, dfs(sub));
        max_salary = max<ll>(max_salary, dfs(sub));
    }

    salary[n] = min_salary + max_salary + 1;
    return salary[n];

}


int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int boss;
        cin >> boss;

        boss--;
        subordinate[boss].push_back(i + 1);
    }

    ll ans = dfs(0);

    cout << ans << endl;

}