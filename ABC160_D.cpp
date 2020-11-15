#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    X --; Y--;

    vector<int> ans(N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++){
            int distance;
            distance = min(j - i, abs(X - i) + 1 + abs(Y - j));
            ans.at(distance) += 1;
        }
    }

    for (int i = 1; i < N; i++) {
        cout << ans.at(i) << endl;
    }
}
