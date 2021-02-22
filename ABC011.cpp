#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, ng1, ng2, ng3;
    cin >> N >> ng1 >> ng2 >> ng3;

    int now = 0;
    for (int i = 0; i < 100; i++) {
        now += 3;
        if (now <= N && now != ng1 && now != ng2 && now != ng3) continue;
        now -=3;

        now += 2;
        if (now <= N && now != ng1 && now != ng2 && now != ng3) continue;
        now -= 2;

        now += 1;
        if (now <= N && now != ng1 && now != ng2 && now != ng3) continue;
        now -= 1;
        break;

    }

    if (now == N) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
}