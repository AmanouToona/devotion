#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<tuple<int, int, int>> plan(0, tuple<int, int, int>());

    int N;
    cin >> N;
    plan.push_back(make_tuple(0, 0, 0));
    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        plan.push_back(make_tuple(t, x, y));
    }

    sort(plan.begin(), plan.end());

    for (int i = 0; i < N; i++) {
        auto [t_u, x_u, y_u] = plan[i];
        auto [t_v, x_v, y_v] = plan[i + 1];

        int d_t = t_v - t_u;
        int d = abs(x_v - x_u) + abs(y_v - y_u);

        if (d_t % 2 == d % 2 && d_t >= d) {
            continue;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;

}