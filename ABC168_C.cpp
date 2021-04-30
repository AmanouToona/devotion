#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const long double PI = 2 * asin(1);

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    long double degree_a = 90 - 360.0 / (12 * 60) * ((H * 60 + M) % (12 * 60));
    long double degree_b = 90 - 360.0 / 60 * ((H * 60 + M) % 60);

    long double rad_a = degree_a / 180.0 * PI;
    long double rad_b = degree_b / 180.0 * PI;
 
    long double x_a = A * cos(rad_a);
    long double y_a = A * sin(rad_a);
    long double x_b = B * cos(rad_b);
    long double y_b = B * sin(rad_b);

    long double ans = sqrt((x_a - x_b) * (x_a - x_b) + (y_a - y_b) * (y_a - y_b));
    cout << fixed << setprecision(10) << ans << endl;

}