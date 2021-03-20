// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_B&lang=ja
// 螺旋本を参考に作成

#include <bits/stdc++.h>
using namespace std;

int q;

void partition(vector<int> &A, int p, int r) {
  int base = A.at(r), save;
  q = p;
  for(int j = p; j < r; j++) {
    if(A.at(j) <= base) {
      save = A.at(q);
      A.at(q) = A.at(j);
      A.at(j) = save;
      q++;
    }
  }
  //添字q番目に基準となる最後の数を入れる
  save = A.at(q);
  A.at(q) = A.at(r);
  A.at(r) = save;
}

int main() {
  int n;
  scanf("%d\n", &n);
  vector<int> A(n);
  for(int i= 0; i < n; i++) {
    scanf("%d\n", &A.at(i));
  }
  partition(A, 0, n - 1);
  
  for(int i = 0; i < n; i++) {
    if(i) printf(" ");
    if(i == q) printf("[");
    printf("%d", A.at(i));
    if(i == q) printf("]");
  }
  printf("\n");
}