// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja
// 螺旋本を参考にして作成

#include <bits/stdc++.h>
using namespace std;

int n;

bool makeNum(vector<int> &A, int i, int m) {
  if(m == 0) return true; // mを作成できたのでtrue
  if(i >= n) return false; // iはA.at(0)からA.at(n-1)までなので作成できなかったのでfalse
  bool res = makeNum(A, i + 1, m) || makeNum(A, i + 1, m - A.at(i));
  // A.at(i)を引かないルートと引くルートを探索する　一方がtrueならresはtrueになる
  return res;
}

int main() {
  int q, m;
  scanf("%d\n", &n);
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &A.at(i));
  }
  scanf("%d\n", &q);
  for(int i = 0; i < q; i++) {
    scanf("%d", &m);
    if( makeNum(A, 0, m) ) printf("yes\n");
    else printf("no\n");
  }
}