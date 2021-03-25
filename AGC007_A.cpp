#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H, W;
vector<string> A;


bool dfs(int h, int w) {
    if (h >= H || w >= W) return false;
    if (A[h][w] == '.') return false;
    if (h == H - 1 && w == W - 1) return true;

    if (h + 1 < H && w + 1 < W && A[h + 1][w] == '#' && A[h][w + 1] == '#') return false;

    return dfs(h + 1, w) || dfs(h, w + 1);

}


int main() {
    cin >> H >> W;

    for (int h = 0; h < H; h++) {
        string input;
        cin >> input;
        A.push_back(input);
    }

    if (dfs(0, 0)) {cout << "Possible" << endl;}
    else {cout << "Impossible" << endl;}
}
