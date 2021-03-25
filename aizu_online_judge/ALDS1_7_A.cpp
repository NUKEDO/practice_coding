// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_A&lang=ja
// 螺旋本を参考に作成

#include <bits/stdc++.h>
using namespace std;
#define NIL -1

struct Node { // 左子右兄弟表現
  int p; // parent 親
  int l; // left 子の中で最も左のもの
  int r; // right 自身の右にいる兄弟
};

void rec(vector<Node> &T, vector<int> &D, int u, int p) {
  D.at(u) = p;
  if(T.at(u).r != NIL) rec(T, D, T.at(u).r, p);
  if(T.at(u).l != NIL) rec(T, D, T.at(u).l, p + 1);
}

int main() {
  int n, v, d, c, l, r;
  scanf("%d\n", &n);
  vector<Node> T(n);
  for(int i = 0; i < n; i++) T.at(i).p = T.at(i).l = T.at(i).r = NIL; 
  for(int i = 0; i < n; i++) { // 入力(0, 3, 1, 4, 10) = (v, d, c, c, c)
    scanf("%d %d", &v, &d);
    for(int j = 0; j < d; j++) { // 子が存在する時に実行
      scanf("%d", &c);
      if(j == 0) T.at(v).l = c;
      else T.at(l).r = c; // [１つ前のc]の右に[新しいc]を入れる
      l = c;
      T.at(c).p = v;
    }
  }
  for(int i = 0; i < n; i++) {
    if(T.at(i).p == NIL) r = i;
  }
  
  vector<int> D(n);
  rec(T, D, r, 0);
  
  int k, x, cnt;
  string str;
  for(int i = 0; i < n; i++) {
    printf("node %d: parent = %d, depth = %d, ", i, T.at(i).p, D.at(i));
    if(T.at(i).p == NIL) str = "root";
    else if(T.at(i).l == NIL) str = "leaf";
    else str = "internal node";
    printf("%s, [", str.c_str());
    x = i;
    k = T.at(x).l;
    if(k != NIL) {
      cnt = 0;
      while(k != NIL) {
        if(cnt != 0) printf(", ");
        printf("%d", k);
        k = T.at(k).r;
        cnt++;
      }
    }
    printf("]\n");
  }
}