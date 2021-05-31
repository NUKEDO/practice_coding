#include <bits/stdc++.h>
using namespace std;

int n;

void printVec(vector<vector<int> > v) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d", v.at(i).at(j));
    }
    printf("\n");
  }
}

void printChild(vector<vector<int> > v) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(v.at(i).at(j)) printf("%d", j);
    }
    printf("\n");
  }
}

int main() {
  int m;
  scanf("%d %d\n", &n, &m);
  vector<vector<int> > g(n, vector<int>(n, 0));
  int a, b;
  for(int i = 0; i < m; i++) {
    scanf("%d %d\n", &a, &b);
    a--;
    b--;
    g.at(a).at(b) = 1;
  }
  
  printVec(g);
  printChild(g);
}