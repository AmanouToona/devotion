#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll S;
    cin >> S;

    ll INF = pow(10, 9);
    
    // int y2 = - S % INF + INF;
    // if (y2 == INF) {
    //     y2 = 0;
    // }

    int y2 = (- S % INF + INF) % INF;

    int y3 = (S + y2) / INF;

    cout << "0 0 1000000000 " << y2 << " 1 " << y3 << endl; 

}