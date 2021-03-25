#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    getline(cin, S);

    vector<string> s;
    string temp;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == ' ') {
            s.push_back(temp);
            temp.clear();
        } else {
            temp.push_back(S[i]);
        }
    }
    s.push_back(temp);

    int N;
    cin >> N;

    vector<string> NG(N);
    for (int i = 0; i < N; i++) {
        cin >> NG[i];
    }

    bool flag = true;
    for (int word_no = 0; word_no < s.size(); word_no++) {
        string word = s[word_no];

        bool flag = false;

        for(auto ng: NG) {
            flag = true;
            if (word.size() != ng.size()) {
                flag = false;
                continue;
            }
            for (int i = 0; i < word.size(); i++) {
                if (ng[i] == '*') continue;
                if (word[i] != ng[i]) flag = false;
            }

            if (flag) break;
        }

        if (flag) {
            for (int i = 0; i < word.size(); i++) {
                cout << '*';
            }
        } else {
            cout << word;
        }

        if (word_no != s.size() - 1) {
            cout << " ";
        }
    }
    
    cout << endl;

}
