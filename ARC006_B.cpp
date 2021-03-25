#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, L;
    cin >> N >> L;
    cin.ignore();

    vector<string> amida;
    for (int i = 0; i < L; i++) {
        string row;
        getline(cin, row);
        amida.push_back(row);
    }

    string goal;
    getline(cin, goal);
    int goal_point;
    for (int i = 0; i < 2 * N; i += 2) {
        if (goal[i] == 'o') goal_point = i;
    }

    int now = goal_point;
    for (int i = L - 1; i >= 0; i--) {
        if (now - 1 > 0 && amida[i][now - 1] == '-') now -= 2;
        else if (now + 1 < (2 * N - 1) && amida[i][now + 1] == '-') now += 2;
    }

    now = now / 2 + 1;

    cout << now << endl;

}
