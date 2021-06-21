// https://twitter.com/kyopro_dekomor2/status/1406890339886006275?s=20
// https://kenkoooo.com/atcoder/#/contest/show/a7a90ea6-4e26-4aaa-bcba-eb6322a6ce22

// https://atcoder.jp/contests/dp/tasks/dp_b


#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> v) {
  for(int i = 0; i < v.size(); i++) {
    if(i) printf(" ");
    printf("%d", v.at(i));
  }
  printf("\n");
}

int main() {
  int n, k;
  scanf("%d %d\n", &n, &k);
  vector<int> v(n), dp(n, INT_MAX);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v.at(i));
  }
  
  for(int i = 0; i < n; i++) {
    if(i <= k) {
      dp.at(i) = abs(v.at(i) - v.at(0));
    } else {
      for(int j = i - k; j <= i - 1; j++) {
        int x = abs(v.at(i) - v.at(j));
        dp.at(i) = min(dp.at(i), x + dp.at(j));
      }
    }
  }
  
  //printVec(dp);
  printf("%d\n", dp.at(n - 1));
}