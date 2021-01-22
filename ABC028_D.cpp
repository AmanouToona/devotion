#include<bits/stdc++.h>
using namespace std;

int main() {
    double N, K;
    cin >> N >> K;

    double ans, numerator;
//  1 ~ K - 1 から 1つ K + 1 ~ N から1つ , K - 1 から1つ, K + 1 ~ N から1つ、全部K 
    numerator = (K - 1) * (N - K) * 6 + (K - 1) * 3 + (N -K) * 3 + 1;
    // cout << numerator << endl;

    ans = numerator / pow(N, 3);

    printf("%.10f", ans);


}
