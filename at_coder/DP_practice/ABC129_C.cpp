// https://atcoder.jp/contests/abc129/tasks/abc129_c
// https://kenkoooo.com/atcoder/#/contest/show/a7a90ea6-4e26-4aaa-bcba-eb6322a6ce22

#include <bits/stdc++.h>
using namespace std;
#define A 1000000007

int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);
  vector<int> bad(m);
  for(int i = 0; i < m; i++) {
    scanf("%d\n", &bad.at(i));
  }
  
  int next_bad = 0;
  bad.push_back(n + 1);
  vector<int> dp(n + 1);
  for(int i = 0; i <= n; i++) {
    if(i <= 1) {
      if(i == bad.at(next_bad)) {
        dp.at(i) = 0;
        next_bad++;
      } else dp.at(i) = 1;
      continue;
    } else if(i == bad.at(next_bad)){
      dp.at(i) = 0;
      next_bad++;
    } else {
      dp.at(i) = (dp.at(i - 1) + dp.at(i - 2)) % A;
    }
  }
  printf("%d\n", dp.at(n));
}