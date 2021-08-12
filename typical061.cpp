#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;

    deque<int> q;
    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;

        if (t == 1) q.push_front(x);
        else if (t == 2) q.push_back(x);
        else {
            cout << q[x - 1] << endl;
        }
    }
}