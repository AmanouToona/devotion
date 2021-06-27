#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    set<string> user;
    for (int i = 1; i <= N; i++) {
        string user_name;
        cin >> user_name;

        if (!user.count(user_name)) {
            cout << i << endl;
            user.insert(user_name);
        }
    }
}