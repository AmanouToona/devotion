#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<bool>> table(H, vector<bool>(W, false));

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (h < B) {
                if (w < A) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            } else {
                if (w < A) {
                    cout << 0;
                } else {
                    cout << 1;
                }
            }
        }
        cout << endl;
    }
}
