#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    int total = 0;
    int max_i = 0;
    for(int i = 1; i <= N; i++) {
        total += i;
        if (total >= N) {
            max_i = i;
            break;
        }
    }

    for (int i = 1; i <= max_i; i++) {
        if (i == total - N) {
            continue;
        }
        cout << i << endl;
    }
}