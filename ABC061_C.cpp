#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> numbers(N, pair<ll, ll>());
    for (ll i = 0; i < N; i++) {
        cin >> numbers[i].first >> numbers[i].second;
    }

    sort(numbers.begin(), numbers.end());

    ll total_num = 0;
    for(auto number: numbers) {
        total_num += number.second;
        if (total_num >= K) {
            cout << number.first << endl;
            return 0;
        }
    }
}

/*
3 6
3 2
2 3
1 1
*/