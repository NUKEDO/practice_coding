// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_C&lang=ja
// 螺旋本の通りに作成
// 参考 https://atcoder.jp/contests/apg4b/tasks/APG4b_aj

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL; // xの親
  Node *x = root; // 'Tの根'
  Node *z; // これから作成するNode
  
  z = (Node *)malloc(sizeof(Node)); // sizeof(型名) 型のバイト単位の大きさ
  // メモリ確保　変数=(型名 *)malloc(確保量)  free(変数)でメモリ解放
  // z = new 型[確保量]　の書き方の方がベター (確保量が１個分なら[]は不要)
  // z = new Node; // newを使った場合はdeleteでメモリ解放
  // delete[] z; []は確保量を指定していないなら不要
  z->key = k;
  z->left = NIL;
  z->right = NIL;
  
  while(x != NIL) {
    y = x;
    if(z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  
  z->parent = y;
  
  if(y == NIL) { // T が空の場合
    root = z; //'Tの根' = z
  } else {
    if(z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node *u) {
  if(u == NIL) return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}
void preorder(Node *u) {
  if(u == NIL) return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}

Node * treeMinimum(Node *x) {
  while(x->left != NIL) x = x->left;
  return x;
}

Node * find(Node *u, int k) { //　「Node *find」と書いてもいいが、変数と見間違えるので書き分けている
  while(u != NIL && k != u->key) {
    if(k < u->key) u = u->left;
    else u = u->right;
  }
  return u;
}

Node * treeSuccessor(Node *x) { // 次節点探し
  if(x->right != NIL) return treeMinimum(x->right);
  Node *y = x->parent;
  while(y != NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

void treeDelete(Node *z) {
  Node *y; // 削除対象
  Node *x; // yの子
  
  if(z->left == NIL || z->right == NIL) y = z; //子が1つ以下ならそのままｚを消す
  else y = treeSuccessor(z); //子が2つなら「中間順巡回(inorder)でzの次にくる節点」を元zの場所に入れる
  
  // yの子xを決める
  if(y->left != NIL) {
    x = y->left;
  } else {
    x = y->right;
  }
  
  if(x != NIL) {
    x->parent = y->parent;
  }
  
  if(y->parent == NIL) {
    root = x;
  } else {
    if(y == y->parent->left) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }
  
  if(y != z) {
    z->key = y->key;
  }
  
  free(y); // メモリ解放
}

int main() {
  int n, num;
  scanf("%d\n", &n);
  string str;
  for(int i = 0; i < n; i++) {
    cin >> str;
    if(str == "insert") {
      scanf("%d\n", &num);
      insert(num);
    } else if(str == "print") {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if(str == "find") {
      scanf("%d\n", &num);
      Node *t = find(root, num);
      if(t != NIL) printf("yes\n");
      else printf("no\n");
    } else if(str == "delete") {
      scanf("%d\n", &num);
      treeDelete(find(root, num));
    }
  }
}