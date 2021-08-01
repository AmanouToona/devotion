#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> point(N, K - Q);

    for (int i = 0; i < Q; i++) {
        int A;
        cin >> A;
        A--;
        point[A]++;
    }

    for (int p: point) {
        if (p <= 0) cout << "No" <<endl;
        else cout << "Yes" << endl;
    }

}