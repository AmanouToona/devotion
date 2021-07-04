#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> Grundy(51, vector<int>(1326, INT_MAX));

    set<int> s;
    for (int w = 0; w <= 50; w++) {
        for (int b = 0; b <= 1325; b++) {
            // printf("%d, %d\n", w, b);
            s.clear();
            if (w > 0) {
                s.insert(Grundy[w - 1][b + w]);
            }
            for (int b_search = b - 1; b_search >= b - b / 2; b_search--) {
                s.insert(Grundy[w][b_search]);
            }

            int g = 0;
            while (s.count(g) != 0) g++;
            Grundy[w][b] = g;
        }
    }

    vector<int> W(N), B(N);
    for (int i = 0; i < N; i++) cin >> W[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans ^= Grundy[W[i]][B[i]]; 
    }

    if (ans != 0) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

}