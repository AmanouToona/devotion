#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    if (H == 1) {
        if (A <= W && B == 0) {
            for (int w = 0; w < W; w++) {
                if (w < A) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    if (W == 1) {
        if (B <= H && A == 0) {
            for (int h = 0; h < H; h++) {
                if (h < B) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            }
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    vector<vector<bool>> table(H, vector<bool>(W, false));  // 0, 1 を記録
    for (int d = 0; d < B; d++) {
        for (int w = 0; w < W; w++) {
            int h = (w + d) % H;
            table[h][w] = true;  // 1: true に変更
        }
    }

    int a = 0, b = 0;
    for (int h = 0; h < H; h++) {
        if (table[h][0]) b++;
    }
    for (int w = 0; w < W; w++) {
        if (table[0][w]) a++;
    }

    a = min(a, W - a);
    b = min(b, H - b);

    if (a == A && b == B) {
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                cout << table[h][w];
            }
            cout << endl;
        }
        return 0;
    }
    cout << "No" << endl;

}
