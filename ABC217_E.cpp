#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;

    priority_queue<int, vector<int>, greater<int>> Aq;
    deque<int> Ad;

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            Ad.push_back(x);
        } else if (q == 2) {
            int x;
            if (Aq.size() != 0) {
                x = Aq.top();
                Aq.pop();
            } else {
                x = Ad.front();
                Ad.pop_front();
            }
            cout << x << endl;
        } else if (q == 3) {
            while (Ad.size() > 0) {
                Aq.push(Ad.front());
                Ad.pop_front();
            }
        }
    }
}