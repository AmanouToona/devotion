#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct A  {
    vector<vector<ll>> a;
    A(vector<vector<ll>> _a) {a = _a;}  // コンストラクタ

    A operator* (const A &other) {
        A res({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    res.a[i][j] += a[i][k] * other.a[k][j];
                }
            }
        }
        return res;
    }

    pair<ll, ll> operator* (const pair<int, int>  xy) {
        ll x, y;
        x = a[0][0] * xy.first + a[0][1] * xy.second + a[0][2];
        y = a[1][0] * xy.first + a[1][1] * xy.second + a[1][2];

        pair<ll, ll> res = make_pair(x, y);
        return res;
    }
};


int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> piece(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> piece[i].first >> piece[i].second;
    }

    int M;
    cin >> M;
    A affine({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
    vector<A> affines;
    affines.push_back(affine);
    for (int i = 0; i < M; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            A op_affine({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}});
            affine = op_affine * affine;
        } else if (op == 2) {
            A op_affine({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}});
            affine = op_affine * affine;
        } else if (op == 3) {
            ll p;
            cin >> p;
            A op_affine({{-1, 0, 2 * p}, {0, 1, 0}, {0, 0 ,1}});
            affine = op_affine * affine;
        } else {
            ll p;
            cin >> p;
            A op_affine({{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}});
            affine = op_affine * affine;
        }

        affines.push_back(affine);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        // cout << "i: " << i << endl;
        int A, B;
        cin >> A >> B;
        pair<ll, ll> res = affines[A] * piece[B - 1]; 

        // cout <<"this is output : ";
        cout << res.first << " " << res.second << endl;

    }

}
