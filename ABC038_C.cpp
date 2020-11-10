#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a;
    vector<int> A;

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a;
        A.push_back(a);
    }

    int left=0, right=0;
    long long ans=0;

    for (left=0; left < N; left++) {
        if (left == right) {
            right++;
        }
        while(right < N && A.at(right - 1) < A.at(right)) {
            right++;
        }
        ans += right - left;
    }

    cout << ans << endl;

}

