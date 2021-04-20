// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D&lang=ja
// 螺旋本を参考に先に作成したmissコードを修正
// C++14で提出(多次元配列があるため)

#include <bits/stdc++.h>
using namespace std;

int n;
int gra = 0; //gradation 減らしていく

void makeColor(vector<vector<int> > &g, vector<int> &color, int a) {
  gra--;
  color.at(a) = gra;
  
  //幅優先探索
  queue<int> q;
  for(int i : g.at(a)) {
    q.push(i);
  }
  
  while(q.size() > 0) {
    int j = q.front();
    q.pop();
    if(color.at(j) != 0) continue;
    
    color.at(j) = gra;
    for(int k : g.at(j)) {
      if(color.at(k) == 0) {
        q.push(k);
      }
    }
  }
  
}

string cc(vector<vector<int> > &g, vector<int> &color, int a, int b) {
  if(color.at(a) == 0) makeColor(g, color, a);
  if(color.at(b) == 0) makeColor(g, color, b);
  
  string ans = (color.at(a) == color.at(b)) ? "yes" : "no";
  return ans;
}

// 隣接リスト表現 ただし双方向
int main() {
  int m, a, b;
  scanf("%d %d\n", &n, &m);
  vector<vector<int> > g(n, vector<int>(0) );//g:graph
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }
  
  vector<int> color(n, 0);
  int com, c, d;
  scanf("%d\n", &com);
  for(int i = 0; i < com; i++) {
    scanf("%d %d", &c, &d);
    string ans = cc(g, color, c, d);
    printf("%s\n", ans.c_str());
  }
}