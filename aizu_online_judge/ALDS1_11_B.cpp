// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B&lang=ja
// 螺旋本を参考に作成（ほぼそのまま）
// 螺旋本と異なりi = 1; i <= n で設計されてるので注意

#include <bits/stdc++.h>
using namespace std;
#define WHITE -1
#define GRAY -2
#define BLACK -3

int n, count_time;
vector<int> color(100 + 1, WHITE), time_s(100 + 1), time_e(100 + 1); //s:start, e:end

void dfs_visit(vector<vector<int> > g, int u) {
  color.at(u) = GRAY;
  time_s.at(u) = ++count_time; // time=0の時、time=1になった後timeが入る (time++だと0が入った後、time=1になる)
  for(int i = 1; i <= n; i++) {
    if(g.at(u).at(i) == 0) continue;
    if(color.at(i) == WHITE) dfs_visit(g, i); // 未踏破=WHITEなので
  }
  color.at(u) = BLACK;
  time_e.at(u) = ++count_time;
}

void dfs(vector<vector<int> > g) {
  stack<int> save;
  count_time = 0;
  for(int i = 1; i <= n; i++) {
    if(color.at(i) == WHITE) dfs_visit(g, i);
  }
}

void printDFS() {
  for(int i = 1; i <= n; i++) {
    printf("%d %d %d\n", i, time_s.at(i), time_e.at(i));
  }
}

void printG(vector<vector<int> > g) {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(j != 1) printf(" ");
      printf("%d", g.at(i).at(j));
    }
    printf("\n");
  }
}

// 隣接リスト表現
int main() {
  int u, k, v;
  scanf("%d\n", &n);
  vector<vector<int> > g(n + 1, vector<int>(100 + 1, 0));//g:graph
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &u, &k);
    for(int j = 1; j <= k; j++) {
      scanf("%d", &v);
      g.at(i).at(v) = 1;
    }
  }
  
  // printG(g);
  
  dfs(g);
  printDFS();
}