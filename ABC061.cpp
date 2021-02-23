#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> numbers(N, pair<int, int>());
    for (int i = 0; i < N; i++) {
        cin >> numbers[i].first >> numbers[i].second;
    }

    sort(numbers.begin(), numbers.end());

    int total_num = 1;
    for(auto [a, b]: numbers) {
        total_num += b;
        if (total_num >= K) {
            cout << a << endl;
            return 0;
        }
    }
}