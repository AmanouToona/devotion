#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int B;
        cin >> B;

        // 2分探索
        int ans_pos = 0;
        if (A[0] >= B) {
            ans_pos = 0;
        } else if (A[N - 1] <= B) {
            ans_pos = N - 1;
        } else {
            int left = 0, right = N - 1;
            while(right - left > 1) {
                int mid = (left + right) / 2;
                if (A[mid] <= B) left = mid;
                else right = mid;
            }
            if (abs(A[left] - B) < abs(A[left + 1] - B)) ans_pos = left;
            else ans_pos = left + 1;
        }

        cout << abs(A[ans_pos] - B) << endl;

    }

    return 0;

}