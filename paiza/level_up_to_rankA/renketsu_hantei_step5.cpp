#include <bits/stdc++.h>
using namespace std;
#define WHITE 1
#define GRAY 2
#define BLACK 3

int n;
vector<vector<int> > g(100, vector<int>(100, 0)),
                     color(100, vector<int>(100, WHITE));
queue<int> ren;

void makeQue() {
  int u = 0;
  ren.push(u + 1);
  
  int check = 1;
  while(check) {
    for(int i = 0; i < n; i++) {
      if(g.at(u).at(i) == 1 && color.at(u).at(i) == WHITE) {
        color.at(u).at(i) = color.at(i).at(u) = BLACK;
        // g.at(u).at(i) = g.at(i).at(u) = 0;
        ren.push(i + 1);
        u = i;
        break;
      }
      if(i == n - 1) check = 0;
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
  scanf("%d\n", &n);
  int a, b;
  for(int i = 0; i < n - 1; i++) {
    scanf("%d %d\n", &a, &b);
    a--;
    b--;
    g.at(a).at(b) = g.at(b).at(a) = 1;
  }
  
  makeQue();
  printQue(ren);
  //printVec(g);
}