#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string ng = "impossible ", ok = "possible";
vector<int> dh = {0, -1, -1, -1, 0, 1, 1, 1}, dw = {1, 1, 0, -1, -1, -1, 0, 1};


bool blacker(vector<string> &S, vector<string> &ans) {
    int H = S.size();
    int W = S[0].size();

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            
            bool white = true;
            if (ans[h][w] == '#') white = false;
            for (int i = 0; i < 8; i++) {
                int vh = h + dh[i];
                int vw = w + dw[i];
                if (vh < 0 || vh >= H) continue;
                if (vw < 0 || vw >= W) continue;
                if (ans[vh][vw] == '#') white = false;
            }

            if (white && S[h][w] == '#') return false;
            if (!white && S[h][w] != '#') return false;
        }
    }
    return true;
}

void whiter(vector<string> &S, vector<string> & ans) {
    int H = S.size();
    int W = S[0].size();

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {

            bool black = true;
            if (S[h][w] == '.') black = false;
            for (int i = 0; i <8; i++) {
                int vh = h + dh[i];
                int vw = w + dw[i];
                if (vh < 0 || vh >= H) continue;
                if (vw < 0 || vw >= W) continue;
                if (S[vh][vw] == '.') black = false;
            }

            if (black) ans[h][w] = '#';
            else ans[h][w] = '.';
        }
    }
}


int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int h = 0; h < H; h++) cin >> S[h];

    vector<string> ans = S;


    whiter(S, ans);
    if (blacker(S, ans)) {
        cout << ok << endl;
        for (auto s: ans)
        cout << s << endl;
    } else {
        cout << ng << endl;
    }

}
