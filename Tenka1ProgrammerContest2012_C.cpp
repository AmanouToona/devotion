#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    vector<string> cards;
    int i = 0;
    while (i < s.size()) {
        string card = "";

        card += s[i];
        i++;
        card += s[i];

        if (s[i] == '1') {
            i++;
            card += s[i];
        }

        cards.push_back(card);
        i++;
    }

    string suits = "SHDC";
    vector<string> ans(100);
    for (char suit: suits) {
        vector<string> temp;
        int count_hand = 0;
        for (auto card: cards) {
            if (card[0] != suit) {
                temp.push_back(card);
                continue;
            }

            if (card[1] <= '9' && card.size() <= 2) {
                temp.push_back(card);
                continue;
            }

            count_hand++;
            if (count_hand == 5) break;
        }

        if (temp.size() < ans.size()) ans = temp;

    }

    if (ans.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;

}