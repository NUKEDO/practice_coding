// 未理解
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=ja
// 螺旋本の通りに作成

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  vector<int> p(n + 1);
  for(int i = 0; i < n; i++) {
    scanf("%d %d\n", &p.at(i), &p.at(i + 1));
  }
  vector<vector<int> > m(n + 1, vector<int>(n + 1, 0));
  // m.at(2).at(5) : M2 ~ M5 までの最小計算回数
  
  for(int l = 2; l <= n; l++) {
    for(int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m.at(i).at(j) = INT_MAX;
      for(int k = i; k <= j - 1; k++) {
        //printf("l:i:j:k = %d:%d:%d:%d\n", l, i, j, k); //テスト出力用
        //printf("m(i)(k):%d + m(k + 1)(j):%d + p(i - 1)*p(k)*p(j):%d*%d*%d\n", m.at(i).at(k), m.at(k + 1).at(j), p.at(i - 1), p.at(k), p.at(j)); //テスト出力用
        m.at(i).at(j) = min(m.at(i).at(j),
                            m.at(i).at(k) + m.at(k + 1).at(j) + p.at(i - 1) * p.at(k) * p.at(j));
      }
    }
  }
  
  printf("%d\n", m.at(1).at(n));
}