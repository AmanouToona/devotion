#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int const MOD = 1000000007;
int const MAX_N = 1000;

struct Matrix {
    int sz; // size of matrix
    ll x[MAX_N][MAX_N];  // MAX_N = 1000 では Segmentation Fault 発生
    Matrix (int num) {
        sz = num;

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                x[i][j] = 0;
            }
        }
    }
};

Matrix multiply(Matrix &A, Matrix &B) {
    Matrix ans(A.sz);

    for (int i = 0; i < A.sz; i++) {
        for (int j = 0; j < B.sz; j++){
            for (int k = 0; k < B.sz;k++) {
                ans.x[i][j] += A.x[i][k] * B.x[k][j];
                ans.x[i][j] %= MOD;
            }
        }
    }

    return ans;
}


Matrix powers(Matrix A, ll T) {
    Matrix ans(A.sz);
    for (int i = 0; i < ans.sz; i++) {
        ans.x[i][i] = 1;
    }

    while (T > 0) {
        if (T & 1ll) ans = multiply(A, ans);
        A = multiply(A, A);
        T >>= 1; 
    };
    return ans;
};



int main() {
    ll N, B, K;
    cin >> N >> B >> K;

    vector<int> c(K);
    for (int i = 0; i < K; i++) {
        cin >> c[i];
    }

    Matrix A(B);

    for (int i = 0; i < B; i++) {
        for (int j = 0; j <K; j++) {
            int nex = (i * 10 + c[j]) % B;
            A.x[i][nex] += 1;
        }
    }

    Matrix ans = powers(A, N);

    cout << ans.x[0][0] << endl;
    return 0;

}
