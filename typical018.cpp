#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const long double PI = acos(-1);

int main() {
    long double T, L, X, Y, Q;
    cin >> T;
    cin >> L >> X >> Y;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int E;
        cin >> E;

        long double y = - (long double)L * sin(2 * PI / (long double)T * E) / 2;
        long double z = (1 - cos(2 * PI / (long double)T * E)) * (long double) L / 2;

        long double xy = sqrt((long double)X * (long double)X + (Y - y) * (Y - y));

        long double ans = atan2(z, xy);
        ans = ans * 180.0L / PI;
        
        cout << fixed << setprecision(10) <<  ans << endl;
        // printf("%.12Lf\n", ans);
    }
    
}
