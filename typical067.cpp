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


ll base_number_converter(ll val, int base1, int base2) {
    // base1 進数の数val を base2進数の数res に変換する

    // 各桁の数字を得る
    vector<int> each_digit = num2vec(val);

    // base1 進数 を 10進数　に変換する
    ll ten_num = 0;
    ll ref = 1;
    reverse(each_digit.begin(), each_digit.end());
    for (int i = 0; i < each_digit.size(); i++) {
        ten_num += ref * each_digit[i];
        ref *= base1;
    }

    // 10 進数を base2 進数に変換する
    vector<int> each_digit2;
    while(ten_num > 0) {
        each_digit2.push_back(ten_num % base2);
        ten_num /= base2;
    }

    reverse(each_digit2.begin(), each_digit2.end());

    ll res = vec2num(each_digit2);

    return res;
}


int main() {
    ll N;
    int K;
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        // 8進数を9進数へ
        N = base_number_converter(N, 8, 9);

        vector<int> nine = num2vec(N);
        for (int j = 0; j < nine.size(); j++) {
            if (nine[j] == 8) nine[j] = 5;
        }

        N = vec2num(nine);

    }

    cout << N << endl;

}
