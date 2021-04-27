// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=ja
// [0] ~ [n - 1] で設計

#include <bits/stdc++.h>
using namespace std;
#define WHITE -1
#define GRAY -2
#define BLACK -3

int n;
vector<vector<int> > g(100 + 1, vector<int>(100 + 1, -1));
vector<int> color(100 + 1, WHITE);
vector<int> d(100 + 1, INT_MAX); //distance

void dijkstra(int u) { //ダイクストラのアルゴリズム
  color.at(u) = BLACK;
  for(int i = 0; i < n; i++) {
    if(g.at(u).at(i) != -1 && color.at(i) != BLACK) {
      color.at(i) = GRAY; // uから到達可能な点をグレーに
      if(d.at(u) + g.at(u).at(i) < d.at(i)) {
        d.at(i) = d.at(u) + g.at(u).at(i);
      }
    }
  }
  
  // for(int i = 0; i < n; i++) printf("%d ", d.at(i)); cout << endl; //テスト出力用
  
  int min_d = INT_MAX; //次のuを探す
  u = -1;
  for(int i = 0; i < n; i++) {
    if(color.at(i) == GRAY && min_d > d.at(i)) {
      min_d = d.at(i);
      u = i;
    }
  }
  if(u == -1) return; // 全部黒の時に終了
  
  dijkstra(u);
}

void print_ans() {
  for(int i = 0; i < n; i++) {
    printf("%d %d\n", i, d.at(i));
  }
}

int main() {
  int u, k, v, c;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    for(int j = 0; j < k; j++) {
      scanf("%d %d", &v, &c);
      g.at(u).at(v) = c;
    }
  }
  
  int x = 0; //0を起点
  d.at(x) = 0;
  dijkstra(x);
  
  print_ans();
}