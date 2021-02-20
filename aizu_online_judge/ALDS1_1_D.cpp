// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n; i++) {
    cin >> num.at(i);
  }
  
  int max_num = num.at(n - 1);
  int max_rev = INT_MIN;
    
  for (int i = n - 2; i >= 0; i--) {
    max_rev = max( max_rev, max_num - num.at(i) ); 
    max_num = max( max_num, num.at(i) );
  }
  
  cout << max_rev << endl;
}