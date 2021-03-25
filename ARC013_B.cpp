#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int C;
    cin >> C;

    vector<int> first, second, third;
    for (int i = 0; i < C; i++) {
        vector<int> baggage(3);
        cin >> baggage[0] >> baggage[1] >> baggage[2];

        sort(baggage.begin(), baggage.end());
        third.push_back(baggage[0]);
        second.push_back(baggage[1]);
        first.push_back(baggage[2]);
    }

    sort(first.begin(), first.end(), greater<int>());
    sort(second.begin(), second.end(), greater<int>());
    sort(third.begin(), third.end(), greater<int>());

    cout << 1LL * first[0] * second[0] * third[0] << endl;

}