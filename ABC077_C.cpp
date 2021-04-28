#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    
    ll ans = 0;
    for (auto b: B) {
        // b よりも小さい a の個数を探索する
        int count_a = 0;
        if (A[N - 1] < b) count_a = N;
        else if (A[0] >= b) count_a = 0;
        else {
            int ok = 0, ng = N - 1;
            while(ng - ok > 1) {
                int mid = (ok + ng) / 2;
                if (A[mid] < b) ok = mid;
                else ng = mid;
            }
            count_a = ok + 1;
        }

        // b よりも大きい c の個数を探索する
        int count_c = 0;
        if (C[N - 1] <= b) count_c = 0;
        else if (C[0] > b) count_c = N;
        else {
            int ok = N - 1, ng = 0;
            while(ok - ng > 1) {
                int mid = (ok + ng) / 2;
                if (C[mid] > b) ok = mid;
                else ng = mid;
            }
            count_c = N - ng - 1;
        }

        ans += 1ll * count_a * count_c;
    }

    cout << ans << endl;

}
