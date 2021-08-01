#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // 尺取り法
    ll section_xor = 0, section_sum = 0, ans=0;
    int r = 0;

    for (int l = 0; l < N; l++) {
        while(r < N && ((section_sum + A[r]) == (section_xor ^ A[r]))) {
            section_sum += A[r];
            section_xor ^= A[r];
            r++;
        }

        ans += r - l;
        section_sum -= A[l];
        section_xor ^= A[l];
    }

    cout << ans << endl;

}