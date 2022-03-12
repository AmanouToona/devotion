#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<pair<char, int>> si;
    for (int i = 0; i < N; i++) {
        si.push_back(make_pair(s[i], i));
    }

    sort(si.begin(), si.end(),
         [&](pair<char, int> i, pair<char, int> j) -> bool {
             if (i.first != j.first) return i.first < j.first;
             return i.second > j.second;
         });

    int j = 0;
    int r = N;
    for (int i = 0; i < N / 2; i++) {
        while ((si[j].second < i || si[j].second > r || r < i) && j < N - 1) {
            j++;
        }
        if (s[i] > si[j].first) {
            char temp = s[i];
            s[i] = si[j].first;
            s[si[j].second] = temp;
            r = si[j].second;
            j++;
        }
    }

    cout << s << endl;
}