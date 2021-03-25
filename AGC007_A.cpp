#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H, W;
vector<string> A;
vector<vector<bool>> fp(8, vector<bool>(8));


bool dfs(int h, int w) {
    if (h >= H || w >= W) return false;
    if (A[h][w] == '.') return false;
    if (h == H - 1 && w == W - 1) return true;

    if (h + 1 < H && w + 1 < W && A[h + 1][w] == '#' && A[h][w + 1] == '#') return false;
    if (h - 1 > 0 && w - 1 > 0 && A[h - 1][w] == '#' && A[h][w - 1] == '#') return false;

    if (dfs(h + 1, w)) {
        fp[h + 1][w] = true;
        return true;
    } else if (dfs(h, w + 1)) {
        fp[h][w + 1] = true;
        return true;
    }

    return false;

}


int main() {
    cin >> H >> W;

    for (int h = 0; h < H; h++) {
        string input;
        cin >> input;
        A.push_back(input);
    }
    fp[0][0] = true;
    if (!dfs(0, 0)) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (A[h][w] == '.') continue;
            if (!fp[h][w]) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;
}
