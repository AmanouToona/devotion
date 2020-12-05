#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; 
    cin >> N;

    vector<int> A(N, 0);
    vector<int> a(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        int sum_ball = 0;
        for (int j = i; j < N; j += i + 1) {
            sum_ball += A[i];
        }
        if (sum_ball % 2 != a[i]) A[i] = 1;
    }

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (A[i] == 1) ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    if (ans.size() == 0) return 0;

    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
}
