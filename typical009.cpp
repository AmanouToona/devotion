#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double const PI = acos(-1);

int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        int x = X[i], y = Y[i];

        vector<double> angle;
        for (int j = 0; j < N; j++) {  // 3つの点のうち1つを固定
            if (i == j) continue;
            int x2 = X[j] - x, y2 = Y[j] - y;  // 固定点を原点として考える
            if (x2 == 0 && y2 == 0) continue;  // atan2 の未定義動作回避のために入れたが不要であった
            double ang = atan2(y2, x2);
            if (ang < 0) ang += 2 * PI;
            angle.push_back(ang);
        }
        sort(angle.begin(), angle.end());

        for (int j = 0; j < angle.size(); j++) {
            double ang1 = angle[j];

            // 2分探索
            double ang_search = ang1 + PI;
            if (ang_search >= 2 * PI) ang_search -= 2 * PI;

            int left = 0, right = angle.size() - 1;
            if (angle[left] > ang_search) left = right;
            else if (angle[right] < ang_search) left = right;
            else {
                while (right - left > 1) {
                    int mid = (left + right) / 2;
                    if (angle[mid] < ang_search) left = mid;
                    else right = mid;
                }
            }
            right = (left + 1) % (angle.size() - 1);
            double ang2 = min<double>(abs(angle[left] - ang1), 2 * PI - abs(angle[left] - ang1));
            ans = max<double>(ans, ang2);
            double ang3 = min<double>(abs(angle[right] - ang1), 2 * PI - abs(angle[right] - ang1));
            ans = max<double>(ans, ang3);
        }
    }
    
    cout << fixed << setprecision(10) << ans / PI * 180<< endl;
}

// 3
// 9 1
// 2 0
// 1 0 
