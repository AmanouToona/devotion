#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> W;
    for (int i = 0; i < N; i++) {
        int w;
        cin >> w;

        sort(W.begin(), W.end());
        vector<int>::iterator iter_lower = lower_bound(W.begin(), W.end(), w);
        if (iter_lower == W.end()) W.push_back(w);
        else *iter_lower = w;
    }

    cout << W.size() << endl;
}
