// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

// /* 動的計画法ありの場合
int fib(int num) {
  vector<int> F(44 + 1); // 条件 n <= 44
  F.at(0) = F.at(1) = 1;
  for(int i = 2; i <= num; i++) {
    F.at(i) = F.at(i - 1) + F.at(i - 2);
  }
  return F.at(num);
}
// */

/* 動的計画法なしの場合
int fib(int num) {
  if(num <= 1) return 1;
  return fib(num - 1) + fib(num - 2);
}
*/

int main() {
  int n;
  scanf("%d\n", &n);
  if(n <= 1) printf("1\n");
  else printf("%d\n", fib(n));
}