// https://twitter.com/kyopro_dekomor2/status/1406890339886006275?s=20
// https://kenkoooo.com/atcoder/#/contest/show/a7a90ea6-4e26-4aaa-bcba-eb6322a6ce22

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  scanf("%d\n", &n);
  vector<int> v(n), dp(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v.at(i));
  }
  
  dp.at(0) = 0;
  dp.at(1) = abs(v.at(1) - v.at(0));
  for(int i = 2; i < n; i++) {
    int x = abs(v.at(i) - v.at(i - 2));
    int y = abs(v.at(i) - v.at(i - 1));
    dp.at(i) = min(x + dp.at(i - 2), y + dp.at(i - 1));
  }
  
  printf("%d\n", dp.at(n - 1));
}