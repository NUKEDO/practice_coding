// https://atcoder.jp/contests/typical90/tasks/typical90_ax
// https://kenkoooo.com/atcoder/#/contest/show/a7a90ea6-4e26-4aaa-bcba-eb6322a6ce22

#include <bits/stdc++.h>
using namespace std;
#define A 1000000007
 
int main() {
  int n, l;
  scanf("%d %d\n", &n, &l);
  vector<int> dp(n + 1, 0);
  for(int i = 0; i <= n; i++) {
    if(i < l) {
      dp.at(i) = 1;
     } else {
      dp.at(i) = (dp.at(i - 1) + dp.at(i - l)) % A;
    }
  }
  printf("%d\n", dp.at(n));
}