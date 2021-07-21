#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1 << 60;
    long long b = 1 << 60;
    long long c = 1LL << 60;

    long long d = 1;
    d <<= 60;

    printf("a: %d\nb: %lld\nc: %lld\nd: %lld", a, b, c, d);

}
