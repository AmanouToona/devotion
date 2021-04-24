#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    if (N % 2 == 1) return 0;

    vector<int> parenthes(N);
    for (int i = 0; i < N / 2; i++){
        parenthes[i] = -1;
        parenthes[N - 1 - i] = 1;
    }

    do {
        int count = 0;
        bool is_right = true;
        for (auto p: parenthes) {
            count += p;
            if (count > 0) {
                is_right = false;
                break;
            };
        }
        
        if (is_right) {
            for (auto p: parenthes) {
                if (p == -1) {
                    cout << '(';
                } else {
                    cout << ')';
                }
            }
        } else {
            continue;
        }

        cout << endl;

    } while(next_permutation(parenthes.begin(), parenthes.end()));
}
