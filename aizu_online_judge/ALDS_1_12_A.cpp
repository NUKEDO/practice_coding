// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=ja
// 螺旋本の通りに作成
// [0]~[n - 1] ではなく [1]~[n] で設計

#include <bits/stdc++.h>
using namespace std;
#define WHITE -1
#define GRAY -2
#define BLACK -3

int n;
vector<vector<int> > g(100 + 1, vector<int>(100 + 1, INT_MAX));
vector<int> color(100 + 1, WHITE);
vector<int> d(100 + 1, INT_MAX); //distance
vector<int> p(100 + 1, -1); //parent

int prim() {
  d.at(1) = 0; // 1を起点に開始
  
  while (1) {
    int min_d = INT_MAX;
    int u = -1;
    
    for(int i = 1; i <= n; i++) { //最短距離の起点uを作成
      if(color.at(i) != BLACK && min_d > d.at(i)) {
        min_d = d.at(i);
        u = i;
      }
    }
    
    // printf("u = %d\n", u); //テスト出力用
    
    if(u == -1) break;
    
    color.at(u) = BLACK; //起点を黒（処理済み)に
    for(int i = 1; i <= n; i++) { //uから到達できるiのみ更新
      if(color.at(i) != BLACK && d.at(i) > g.at(u).at(i)) {
        d.at(i) = g.at(u).at(i);
        p.at(i) = u;
        color.at(i) = GRAY;
      }
    }
  }
  
  /* //テスト出力用
  for(int i = 1; i <= n; i++) {
    printf("%d ", d.at(i));
  } printf("\n");
  */
  
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += d.at(i);
  }
  return sum;
}

int main() {
  int num;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("%d", &num);
      if(num != -1) g.at(i).at(j) = num; // -1じゃない時のみ入力
    }
  }
  
  printf("%d\n", prim());
}