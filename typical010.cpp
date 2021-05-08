#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<ll> class1(1, 0), class2(1, 0);

    for (int i = 0; i < N; i++) {
        int c, p;
        cin >> c >> p;
        if (c == 1) {
            class1.push_back(p);
            class2.push_back(0);
        } else {
            class1.push_back(0);
            class2.push_back(p);
        }
    }

    // 累積和の計算
    for (int i = 0; i < N; i++) {
        class1[i + 1] += class1[i];
        class2[i + 1] += class2[i];
    }

    // クエリー処理
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << class1[R] - class1[L - 1] << " " << class2[R] - class2[L - 1] << endl;
    }

}