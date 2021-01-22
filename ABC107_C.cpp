# include<bits/stdc++.h>
using namespace std;

int INF = 1001001001;

int main() { 
    int N, K;
    cin >> N >> K;
    
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    int left = 0, right = K - 1, time = INF;
    while(right < N) {
        time = min(time, abs(x[left]) +abs(x[right] - x[left]));
        time = min(time, abs(x[right]) + abs(x[left] - x[right]));
        left ++;
        right ++;
    }

    cout << time << endl;

}

