#include<bits/stdc++.h>
using namespace std;

int main (){
    int N, A, B;
    cin >> N >> A >> B;

    vector<long long> S;
    for (int n = 0; n < N; n++) {
        long long s;
        cin >> s;
        S.push_back(s);
    }

    float P, Q;

    if (max_element(S.begin(), S.end()) - min_element(S.begin(), S.end()) == 0) {
        cout << -1 << endl;
        return 0;
    }


    P = (float)B / (float)(*max_element(S.begin(), S.end()) - *min_element(S.begin(), S.end()));
    Q = (float)A - (float)accumulate(S.begin(), S.end(), 0.0) / N * P;

    if (P == 0) {
        cout <<  -1 << endl;
    }

    printf("%.7f %.7f", P, Q);

}