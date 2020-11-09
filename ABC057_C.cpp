#include <bits/stdc++.h>

using namespace std;


int64_t countDigits (int64_t a) {
    int64_t ans = 0;
    while (a != 0) {
        a /= 10;
        ans++;
    }
    return ans;
}


int main() {
    int64_t N, ans, b;
    cin >> N;

    ans = 1000000;

    for (int64_t i = 1; i <= int(sqrt(N)); i++){
        if (N % i == 0) {
            int64_t f = countDigits(N / i);
            ans = f;
        }
    }
    cout << ans << endl;
    return 0;
}
