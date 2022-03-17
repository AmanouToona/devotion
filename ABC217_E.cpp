#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;

    deque<int> A;
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;

        if (q == 1) {
            int x;
            cin >> x;
            A.push_back(x);
        } else if (q == 2) {
            int x = A.front();
            A.pop_front();
            cout << x << endl;
        } else if (q == 3) {
            sort(A.begin(), A.end());
        }
    }
}