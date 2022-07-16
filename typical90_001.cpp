#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool judge(vector<int>& A, int score, int K, int L) {
    int left = 0;
    int count = 0;
    for (int a : A) {
        if (a - left >= score) {
            count++;
            left = a;
        }
    }
    if (L - left >= score) count++;
    return count > K;
};

int main() {
    int N, L, K;
    cin >> N >> L >> K;

    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    int l = 1;
    int r = L;

    while (r - l > 1) {
        int mid = (l + r) / 2;

        bool can = judge(A, mid, K, L);
        if (can) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;
}
