// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja
// 最大数が来るとタイムオーバーになる

#include <bits/stdc++.h>
using namespace std;

void makeNum(vector<int> A, int m) {
  string ans = "no";
  int n = A.size(), sum;
  for(int tmp = 0; tmp < (1 << n); tmp++) { // (1 << n)は2のn乗を意味する
    bitset<20> bit(tmp); // 0 ~ 2のn乗-1 までの2進数を作成　(bitset<n>はできないので必要最大数で作成)
    sum = 0;
    for(int i = 0; i < n; i++) {
      if(bit.test(i)) {
        sum += A.at(i);
      }
    }
    if(sum == m) {
      ans = "yes";
      break;
    }
  }
  printf("%s\n", ans.c_str());
}

int main() {
  int n, q, m;
  scanf("%d\n", &n);
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &A.at(i));
  }
  scanf("%d\n", &q);
  for(int i = 0; i < q; i++) {
    scanf("%d", &m);
    makeNum(A, m);
  }
}