// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja
// 螺旋本を参考に作成
// 螺旋本と異なりi = 1; i <= n で設計されてるので注意

#include <bits/stdc++.h>
using namespace std;
#define WHITE -1
#define GRAY -2
#define BLACK -3

int n;

/*
int count_time;
vector<int> color(100 + 1, WHITE), nt(100 + 1, 1);
vector<int> time_s(100 + 1), time_e(100 + 1); //s:start, e:end
*/
vector<int> dis(100 + 1, -1);

/*
int next(vector<vector<int> > g, int u) {
  for(int i = nt.at(u); i <= n; i++) {
    nt.at(u) = i + 1;
    if(g.at(u).at(i) == 1) return i;
  }
  return -1;
}

void dfs_visit(vector<vector<int> > g, int u) {
  stack<int> save;
  
  save.push(u);
  color.at(u) = GRAY;
  time_s.at(u) = ++count_time;
  
  while(save.size() > 0) {
    u = save.top();
    int v = next(g, u);
    if(v == -1) {
      save.pop();
      color.at(u) = BLACK;
      time_e.at(u) = ++count_time;
    } else {
      if(color.at(v) == WHITE) {
        color.at(v) = GRAY;
        time_s.at(v) = ++count_time;
        save.push(v);
      }
    }
  }
}

void dfs(vector<vector<int> > g) {
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
*/

void bfs(vector<vector<int> > g) {
  int distance = 0;
  queue<int> q;
  dis.at(1) = distance; // 始点 1
  distance++;
  for(int i = 1; i <= n; i++) {
    if(g.at(1).at(i) == 1) {
      dis.at(i) = dis.at(1) + 1;
      q.push(i);
      // cout << "q_in " << i << endl; //テスト出力用
    }
  }
  while(q.size() > 0) {
    int u = q.front();
    // cout << "u = " << u << ", " << endl; //テスト出力用
    q.pop();
    for(int i = 1; i <= n; i++) {
      if(g.at(u).at(i) == 0) continue;
      if(dis.at(i) != -1) continue; // 処理済み
      dis.at(i) = dis.at(u) + 1;
      q.push(i);
      // cout << "q_in " << i << endl; //テスト出力用
    }
  }
}

void printBFS() {
  for(int i = 1; i <= n; i++) {
    printf("%d %d\n", i, dis.at(i));
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
  
  // dfs(g); // 深さ優先探索
  // printDFS();
  
  bfs(g); // 幅優先探索
  printBFS();
}