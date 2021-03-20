#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int na, nb;
    cin >> na >> nb;

    unordered_set<int> a;
    int numerator=0, denominator=na;

    for (int i = 0; i < na; i++) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }

    for (int i = 0; i < nb; i++) {
        int bi;
        cin >> bi;
        if (a.count(bi)) numerator++;
        else denominator++;
    }

    double ans;
    ans = numerator *  1.0/ denominator;
    printf("%f11", ans);
}