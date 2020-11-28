#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, frontB=0, rearA=0, ans=0, both = 0;

    cin >> N;

    for (int n = 0; n < N; n++) {
        string S;
        cin >> S;

        for (int i = 0; i < S.size() - 1; i++) {
            if (S[i] == 'A' && S[i + 1] == 'B') ans++;
        }
        
        if (S[0] == 'B') frontB++;
        if (S.back() == 'A') rearA++;
        if (S[0] == 'B' && S.back() == 'A') both++;
    }

    ans += min(frontB, rearA);
    if (both == rearA && both == frontB && ans != 0 && rearA >= 2) ans--;

    cout << ans << endl;
}
