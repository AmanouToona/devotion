#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int x, y;
    string W;
    cin >> x >> y >> W;
    x--; y--;

    vector<string> C(9);
    for (int i = 0; i < 9; i++) {
        cin >> C[i];
    }

    vector<char> ans;
    int vec_h = 0;
    int vec_w = 0;
    if (W.find("R")!= std::string::npos) vec_w = 1;
    else if (W.find("L")!= std::string::npos) vec_w = -1;
    if (W.find("U")!= std::string::npos) vec_h = -1;
    else if (W.find("D")!= std::string::npos) vec_h = 1;

    for (int i = 0; i < 4; i++) {
        ans.push_back(C[y][x]);
        
        if (vec_w != 0) {
            if (x == 8) vec_w = -1;
            else if (x == 0) vec_w = 1;
        }

        if (vec_h != 0) {
            if (y == 8) vec_h = -1;
            else if (y == 0) vec_h = 1;
        }

        x += vec_w;
        y += vec_h;
    }

    for (char a: ans) {
        cout << a;
    }
    cout << endl;

}

/*
3 5 R
790319030
091076399
143245946
590051196
398226115
442567154
112705290
716433235
221041645

*/
