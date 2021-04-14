// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A&lang=ja
// 螺旋本を参考に作成

#include <bits/stdc++.h>
using namespace std;

// 隣接リスト表現
int main() {
  int n, u, k, v;
  scanf("%d\n", &n);
  vector<vector<int> > g(n + 1, vector<int>(100 + 1, 0));//g:graph
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &u, &k);
    for(int j = 1; j <= k; j++) {
      scanf("%d", &v);
      g.at(i).at(v) = 1;
    }
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(j != 1) printf(" ");
      printf("%d", g.at(i).at(j));
    }
    printf("\n");
  }
}