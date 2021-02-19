// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B&lang=ja

#include <bits/stdc++.h>
using namespace std;
  
int gcd(int big, int small) {  
  int save, ans;
  if(big < small) {
    save = big;
    big = small;
    small = save;
  }
  
  if (big % small == 0) {
    return small;
  }
  
  ans = gcd(big % small, small);
  return ans;
}

int main() {
  int x, y, z;
  cin >> x >> y;
  
  cout << gcd(x, y) << endl;
}