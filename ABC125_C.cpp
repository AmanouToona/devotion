#include<bits/stdc++.h>
using namespace std;

template <typename T>
T gcd(T a, T b) {
    if (a == INT_MAX) return b;
    if (b == INT_MAX) return a;
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    a %= b;
    return gcd(a, b);
}


template <typename T>
struct SegmentTree {
    private:
    const T INF = numeric_limits<T>::max();
        int n;
        vector<T> node;
    
    public:
        SegmentTree(vector<T> v) {
            int sz = v.size();

            n = 1;
            while (n < sz) {n *= 2;}
            node.resize(2 * n - 1, v.at(sz - 1));

            for (int i = 0; i <sz; i++) node[i + n - 1] = v[i];
            for (int i = n - 2; i >= 0; i--) node[i] = gcd<T>(node[2 * i + 1], node[2 * i + 2]);
        }

        void update(int x, T val) {
            x += (n - 1);
            node[x] = val;
            while (x > 0) {
                x = (x - 1) / 2;
                node[x] = gcd(node[2 * x + 1], node[2 * x + 2]);
            }
        }

        T query() {  // [left, right) の gcd を求める
            return node[0];
            // return sub_query(left, right, 0, left=0, -1);
        }

    // private:
    //     T sub_query (int a, int b, int k, int left, int right) {
    //         if (right < 0) right = n;
    //         if (a <= left && b >= right) return node[k];
    //         if (right < a || left > b) return 1;
            
    //         T v_left = sub_query(a, b, 2 * k + 1, left, (left + right) / 2);
    //         T v_right = sub_query(a, b, 2 * k + 2, (left + right) / 2, right);

    //         return gcd(v_left, v_right);
    //     }
};
 

int main() {
    int N;
    vector<int> A;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    SegmentTree<int> seg = SegmentTree<int>(A);
    int ans = 0, temp;
    for (int i = 0; i < N; i++){

        temp = A.at(i);
        seg.update(i, INT_MAX);
        ans = max(ans, seg.query());
        seg.update(i, temp);
    }
    cout << ans << endl;

}
