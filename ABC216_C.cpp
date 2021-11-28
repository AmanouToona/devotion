#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   ll N;
   cin >> N;

   vector<char> ans;

   while(N != 0) {
       if (N % 2 == 0) {
           ans.push_back('B');
           N /= 2;
       } else {
           ans.push_back('A');
           N -= 1;
       }
   }

   reverse(ans.begin(), ans.end());
   for (char a: ans) {
       cout << a;
   }
   cout << endl;

}