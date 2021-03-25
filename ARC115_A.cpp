#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    int even=0, odd=0;
    ll ans;
    for (int i = 0; i < N; i++) {
        string answer;
        cin >> answer;

        int one = 0;
        for (int m = 0; m < M; m++) {
            if (answer[m] == '1') one++;
        }

        if (one % 2 == 0) even++;
        else odd++;
    }

    ans = 1LL * odd * even;


    cout << ans << endl;

}