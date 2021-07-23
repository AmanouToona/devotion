#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int counting = 0;

void print_vec(vector<int> &number) {
    for (int a: number) cout << a;
    cout << endl;
}

void print_vec_num(vector<int> &number) {
    bool non_zero = false;
    for (int a: number) {
        if (a != 0 || non_zero) cout << a;
        if (a != 0) non_zero = true;
    }
}


void dfs(vector<int> &number, int digit, int k, int no_zero) {
    if (number.size() == digit) {
        counting++;
        return;
    }

    if (!no_zero) {
        for (int i= 0; i < 10; i++) {
            if (number.size() == digit - 1 && i == 0) continue; 
            number.push_back(i);
            dfs(number, digit, k, no_zero | (i != 0));
            if (counting >= k) return;
            number.pop_back();
        }
        return;
    }

    if (number.size() == 0) {
        for (int i = 0; i < 10; i++) {
            number.push_back(i);
            dfs(number, digit, k, i != 0);
            if (counting >= k) return;
            number.pop_back();
        }
    }

    int num_size = number.size();
    for (int i = max(0, number[num_size - 1] - 1); i <= min(9, number[num_size - 1] + 1); i++) {
        number.push_back(i);
        dfs(number, digit, k, no_zero | (i != 0));
        if (counting >= k) return;
        number.pop_back();
    }
}




int main() {
    int K;
    cin >> K;

    vector<int> ans;
    dfs(ans, 11, K, false);

    print_vec_num(ans);
    cout << endl;

}
