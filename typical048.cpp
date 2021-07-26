#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> point;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        point.push_back(B);
        point.push_back(A - B);
    }

    sort(point.rbegin(), point.rend());

    ll ans = 0;
    for (int i = 0; i < K; i++) {
        ans += point[i];
    }

    cout << ans << endl;
}