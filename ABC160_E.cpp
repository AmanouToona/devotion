#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<int> P(A), Q(B), R(C);
    for (int i = 0; i < A; i++) cin >> P[i];
    for (int i = 0; i < B; i++) cin >> Q[i];
    for (int i = 0; i < C; i++) cin >> R[i];

    sort(P.begin(), P.end(), greater<int>());
    sort(Q.begin(), Q.end(), greater<int>());
    sort(R.begin(), R.end(), greater<int>());

    priority_queue<int, vector<int>, greater<int>> eat;
    for (int i = 0; i < X; i++) eat.push(P[i]);
    for (int i = 0; i < Y; i++) eat.push(Q[i]);

    int r_front = 0;
    while (r_front < C && eat.top() < R[r_front]) {
        eat.pop();
        eat.push(R[r_front]);
        r_front++;
    }

    ll ans = 0;
    while(!eat.empty()) {
        ans += eat.top();
        eat.pop();
    }

    cout << ans << endl;

}
