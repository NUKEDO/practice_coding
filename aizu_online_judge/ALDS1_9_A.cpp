// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_A&lang=ja
// 螺旋本を参考に作成

#include <bits/stdc++.h>
using namespace std;

int parent(int i) {return i / 2;}
int left(int i) {return i * 2;}
int right(int i) {return i * 2 + 1;}


int main() {
  int n, num;
  scanf("%d\n", &n);
  vector<int> A(n + 1);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &A.at(i));
  }
  
  for(int i = 1; i <= n; i++) {
    printf("node %d: key = %d, ", i, A.at(i));
    if(parent(i) != 0) printf("parent key = %d, ", A.at( parent(i) ) );
    if(left(i) <= n) printf("left key = %d, ", A.at( left(i) ) );
    if(right(i) <= n) printf("right key = %d, ", A.at( right(i) ) );
    printf("\n");
  }
}