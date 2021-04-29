// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C&lang=ja
// 螺旋本の通りに作成

// [0] ~ [n - 1] で設計

#include <bits/stdc++.h>
using namespace std;
#define WHITE -1
#define GRAY -2
#define BLACK -3

int n;
vector<vector<pair<int, int> > > adj(10000, vector<pair<int, int> >(0));
vector<int> d(10000,INT_MAX);

void dijkstra() {
  priority_queue<pair<int, int> > PQ; //priority_queueは最大値を優先する
  vector<int> color(10000, WHITE);
  
  d.at(0) = 0;
  PQ.push(make_pair(0, 0));
  color.at(0) = GRAY;
  
  while(!PQ.empty()) {
    pair<int, int> f = PQ.top();
    PQ.pop();
    int u = f.second;
    color.at(u) = BLACK;
    
    if (d.at(u) < f.first * (-1)) continue;
    
    for(int j = 0; j < adj.at(u).size(); j++) {
      int v = adj.at(u).at(j).first;
      if(color.at(v) == BLACK) continue;
      if(d.at(v) > d.at(u) + adj.at(u).at(j).second) {
        d.at(v) = d.at(u) + adj.at(u).at(j).second;
        color.at(v) = GRAY;
        PQ.push(make_pair(d.at(v) * (-1), v)); //-1をかけて逆順にする
      }
    }
    
  }
}

void print_d() {
  for(int i = 0; i < n; i++) {
    if(d.at(i) == INT_MAX) printf("%d -1\n", i);
    else printf("%d %d\n", i, d.at(i));
  }
}

int main() {
  int u, k, v, c;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    for(int j = 0; j < k; j++) {
      scanf("%d %d", &v, &c);
      adj.at(u).push_back(make_pair(v, c));
    }
  }
  
  dijkstra();
  
  print_d();
}