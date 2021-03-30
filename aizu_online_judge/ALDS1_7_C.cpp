// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_C&lang=ja
// 螺旋本を参考に作成

#include <bits/stdc++.h>
using namespace std;
#define NIL -1

int n;

struct Node {
  int p; //parent
  int l; //left
  int r; //right
};

int makePreorder(vector<Node> T, vector<int> &P, int u, int i) {
  if(u == NIL) return i;
  
  P.at(i) = u;
  i++;
  int j = makePreorder(T, P, T.at(u).l, i);
  j = makePreorder(T, P, T.at(u).r, j);
  return j;
}

int makeInorder(vector<Node> T, vector<int> &P, int u, int i) {
  if(u == NIL) return i;
  
  int j = makeInorder(T, P, T.at(u).l, i);
  P.at(j) = u;
  j++;
  int k = makeInorder(T, P, T.at(u).r, j);
  return k;
}

int makePostorder(vector<Node> T, vector<int> &P, int u, int i) {
  if(u == NIL) return i;
  
  int j = makePostorder(T, P, T.at(u).l, i);
  int k = makePostorder(T, P, T.at(u).r, j);
  P.at(k) = u;
  k++;
  return k;
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
  
  vector<int> Pre(n), In(n), Post(n);
  makePreorder(T, Pre, root, 0);
  makeInorder(T, In, root, 0);
  makePostorder(T, Post, root, 0);
  
  printf("Preorder\n");
  for(int i = 0; i < n; i++) {
    printf(" %d", Pre.at(i));
  }
  printf("\n");
  
  printf("Inorder\n");
  for(int i = 0; i < n; i++) {
    printf(" %d", In.at(i));
  }
  printf("\n");
  
  printf("Postorder\n");
  for(int i = 0; i < n; i++) {
    printf(" %d", Post.at(i));
  }
  printf("\n");
}