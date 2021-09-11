#include<bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> num2vec(ll val) {
    vector<int> res;

    while(val > 0) {
        res.push_back(val % 10);
        val /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}


ll vec2num(vector<int> val) {
    ll res = 0;

    ll ref = 1;
    reverse(val.begin(), val.end());
    for (int i = 0; i < val.size(); i++) {
        res += ref * val[i];
        ref *= 10;
    }

    return res;
}


string base_number_converter(string val, int base1, int base2) {
    // base1 進数の数val を base2進数の数res に変換する

    // base1 進数 を 10進数　に変換する
    ll ten_num = 0;
    ll ref = 1;
    reverse(val.begin(), val.end());
    for (int i = 0; i < val.size(); i++) {
        ten_num += ref * (val[i] - '0');
        ref *= base1;
    }

    // 10 進数を base2 進数に変換する
    vector<int> each_digit;
    if (ten_num == 0) each_digit.push_back(0);
    else {
        while(ten_num > 0) {
            each_digit.push_back(ten_num % base2);
            ten_num /= base2;
        }
    }

    reverse(each_digit.begin(), each_digit.end());

    string res;
    for (auto a: each_digit) {
        res.push_back(a + '0');
    }

    return res;
}


int main() {
    string N;
    int K;
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        // 8進数を9進数へ
        N = base_number_converter(N, 8, 9);

        for (int j = 0; j < N.size(); j++) {
            if (N[j] == '8') N[j] = '5';
        }

    }

    cout << N << endl;

}
