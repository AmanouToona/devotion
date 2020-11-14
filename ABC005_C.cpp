#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, M;
    vector<int> A, B;

    cin >> T >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        B.push_back(b);
    }

    string ans = "no";
    int customer = 0;
    for (int i = 0; i < N; i++) {
        if (A.at(i) <= B.at(customer) && B.at(customer) <= A.at(i) + T) {
            customer ++;
            if (customer == B.size()) {
                ans = "yes";
                break;
            }
        }
        else if (A.at(i) > B.at(customer)) {
            break;
        }
    }
    cout << ans << endl;
}


