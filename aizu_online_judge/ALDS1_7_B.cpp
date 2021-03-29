// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_B&lang=ja
// 螺旋本を参考に作成

#include <bits/stdc++.h>
using namespace std;
#define NIL -1

int n;

struct Node {
  int p; //parent
  int l; //left
  int r; //right
  int d; //depth
  int h; //hight
};

void setDepth(vector<Node> &T, int u, int d) {
  if(u >= n) return;
  T.at(u).d = d;
  d++;
  if(T.at(u).l != NIL) setDepth(T, T.at(u).l, d);
  if(T.at(u).r != NIL) setDepth(T, T.at(u).r, d);
}

int setHeight(vector<Node> &T, int u) {
  if(T.at(u).l == NIL && T.at(u).r == NIL) return 0;
  int h1 = NIL, h2 = NIL;
  if(T.at(u).l != NIL) h1 = setHeight(T, T.at(u).l); 
  if(T.at(u).r != NIL) h2 = setHeight(T, T.at(u).r);
  return T.at(u).h = 1 + max(h1, h2);
}

void makeSibling(vector<Node> T, vector<int> &s, int u) {
  if(u == NIL) return;
  
  if(T.at(u).p == NIL) s.at(u) = -1;
  if(T.at(u).l != NIL && T.at(u).r != NIL) {
    s.at( T.at(u).l ) = T.at(u).r;
    s.at( T.at(u).r ) = T.at(u).l;
  }
  makeSibling(T, s, T.at(u).l);
  makeSibling(T, s, T.at(u).r);
}

int main() {
  int v, l, r, root;
  scanf("%d\n", &n);
  vector<Node> T(n);
  for(int i = 0; i < n; i++) T.at(i).p = NIL;
  for(int i = 0; i < n; i++) {
    scanf("%d %d %d\n", &v, &l, &r);
    T.at(v).l = l;
    T.at(v).r = r;
    if(l != NIL) T.at(l).p = v;
    if(r != NIL) T.at(r).p = v;
  }
  for(int i = 0; i < n; i++) {
    if(T.at(i).p == NIL) {
      root = i;
      break;
    }
  }
  setDepth(T, root, 0);
  setHeight(T, root);
  
  vector<int> s(n, -1);
  makeSibling(T, s, root);
  
  
  int deg;
  string mes;
  for(int i = 0; i < n; i++) {
    deg = 0;
    if(T.at(i).l != NIL) deg++;
    if(T.at(i).r != NIL) deg++;
    printf("node %d: parent = %d, sibling = %d, ", i, T.at(i).p, s.at(i));
    printf("degree = %d, depth = %d, height = %d, ", deg, T.at(i).d, T.at(i).h);
    if(i == root) mes = "root";
    else if(T.at(i).l == NIL && T.at(i).r == NIL) mes = "leaf";
    else mes = "internal node";
    printf("%s\n", mes.c_str());
  }
}