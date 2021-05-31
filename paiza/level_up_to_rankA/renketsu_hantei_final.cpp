#include <bits/stdc++.h>
using namespace std;
#define WHITE 1
#define GRAY 2
#define BLACK 3

int n, m, sum = 0;
vector<int> color(100, WHITE);
vector<vector<int> > g(100, vector<int>(100, 0));
queue<int> ren;

void makeBlack() {
  color.at(0) = BLACK;
  sum++;
  ren.push(0);
  
  while(ren.size() > 0) {
    int u = ren.front();
    ren.pop();
    
    for(int i = 0; i < n; i++) {
      if(g.at(u).at(i) == 1 && color.at(i) == WHITE) {
        color.at(i) = BLACK;
        ren.push(i);
        sum++;
      }
    }
  }
}

void printVec(vector<vector<int> > v) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d", v.at(i).at(j));
    }
    printf("\n");
  }
}

void printQue(queue<int> x) {
  queue<int> q = x;
  while(q.size() > 0) {
    printf("%d\n", q.front());
    q.pop();
  }
}

int main() {
  scanf("%d %d\n", &n, &m);
  int a, b;
  for(int i = 0; i < m; i++) {
    scanf("%d %d\n", &a, &b);
    a--;
    b--;
    g.at(a).at(b) = g.at(b).at(a) = 1;
  }
  
  if(m >= n - 1) makeBlack();
  
  string ans = (sum == n) ? "YES" : "NO";
  printf("%s\n", ans.c_str());
  
  //printQue(ren);
  //printVec(g);
}