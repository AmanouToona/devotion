# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    int a, odd=0, even=0;
    for (int i = 0; i < N; i++) {
        cin >> a;

        if (a % 2 == 0) {
            even += 1;
        }
        else {
            odd += 1;
        }
    }

    long long even_choice = 1, _choice=1;
    for (int i = 1; i <= even; i++) {
        _choice = _choice * (even + 1 - i) / i;
        even_choice += _choice;
    }

    long long odd_choice = 1;
    _choice = 1;
    for (int i = 1;  i <= odd; i++) {
        _choice = _choice * (odd + 1 - i) / i;

        if (P == 0 && i % 2 == 1) {
            continue;
        }
        else if (P == 1 && i % 2 == 0) {
            continue;
        }

        odd_choice += _choice;
    }

    if (P == 1) {
        odd_choice -= 1;
    }

    cout << even_choice * odd_choice << endl;
}
