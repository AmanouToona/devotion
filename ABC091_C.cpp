#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> red(N), blue(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        red[i] = make_pair(a, b);
    }

    for (int i = 0; i < N; i++) {
        int c, d;
        cin >> c >> d;
        blue[i] = make_pair(c, d);
    }

    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());

    vector<pair<int, int>> stock;
    int r_point = 0;
    int count = 0;
    for (auto [b_x, b_y]: blue) {
        while (r_point < red.size() && red[r_point].first < b_x) {
            stock.push_back(red[r_point]);
            r_point++;
        }

        if (stock.size() == 0) continue;

        // stock は x座標が現在探索しているblue よりも小さい red のy座標降順のvector
        sort(stock.begin(), stock.end(), 
            [](pair<int, int> a, pair<int, int> b){
                return a.second > b.second;
            }
        );

        if (stock[stock.size() - 1].second > b_y) continue;

        int r_res = 0;
        while (stock[r_res].second > b_y) {
            r_res++;
        }

        stock.erase(stock.begin() + r_res);

        count++;

    }

    cout << count << endl;

    return 0;

}
