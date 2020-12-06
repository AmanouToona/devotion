#include<bits/stdc++.h>
using namespace std;

int main() {
    // input
    int H, W, K;
    cin >> H >> W >> K;

    vector<string> s(H);
    for (int h = 0; h < H; h++) {
        cin >> s[h];
    }

    // sum strawberrys in rows
    vector<int> sum_row;
    for (int h = 0; h < H; h++) {
        int strawberry = 0;
        for (int w = 0; w < W; w++) {
            if (s[h][w] == '#') strawberry++;
        }
        sum_row.push_back(strawberry);
    }

    vector<vector<int>> ans;
    
    int stacking = 0;
    bool first = true;

    int count_cut = 0;
    for (int h = 0; h < H; h++) {
        if (sum_row[h] == 0 && first) {stacking++; continue;}
        first = false;
        
        if (sum_row[h] == 0 && h != 0) {
            vector<int> ans_row2(ans.back().size());
            std::copy(ans.back().begin(), ans.back().end(), ans_row2.begin());
            ans.push_back(ans_row2);
            continue;
        }

        if (sum_row[h] >= 1) count_cut++;

        int count_row_strawberry = 0;
        vector<int> ans_row;
        for (int w = 0; w < W; w++) {
            if (s[h][w] == '#') {
                count_row_strawberry ++;
                if (count_row_strawberry >= 2) count_cut++;
            }
            ans_row.push_back(count_cut);
        }
        ans.push_back(ans_row);
    }

    for (stacking; stacking > 0; stacking--) {
        for (int w = 0; w < W; w++) {
            if (w != 0); {cout << " ";}
            cout << ans[0][w];
        }
        cout << endl;
    }

    for (auto ans_h : ans) {
        for (int w = 0; w < W; w++) {
            if (w != 0) {cout << " ";}
            cout << ans_h[w];
        }
        cout << endl;
    }
}