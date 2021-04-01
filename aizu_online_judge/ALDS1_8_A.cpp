// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_A&lang=ja
// 螺旋本の通りに作成

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
  Node *z;
  
  z = (Node *)malloc(sizeof(Node)); // sizeof(型名) 型のバイト単位の大きさ
  // メモリ確保 変数=(型名 *)malloc(確保量)  free(変数)でメモリ解放
  z->key = k;
  z->left = NIL;
  z->right = NIL;
  
  while(x!= NIL) {
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
    }
  }
}