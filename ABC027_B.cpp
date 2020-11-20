#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    for (int i = 1; i < N; i++) {
        a[i] += a[i - 1];
    }

    int a_ave;
    if (a[N - 1] % N != 0) {
        cout << -1 << endl;
        return 0;
    }

    a_ave = a[N - 1] / N;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == a_ave * (i + 1)) {
            continue;
        }
        else {
            ans += 1;
        }
    }

    cout << ans << endl;

}
