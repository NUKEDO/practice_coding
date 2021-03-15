// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_C&lang=ja
// 螺旋本を見ながら作成

#include <bits/stdc++.h>
using namespace std;

struct Node{
  int key;
  Node *prev, *next;
};

Node *nil; //番兵作成

void init() { // リスト初期化
  nil = (Node *)malloc(sizeof(Node)); //メモリを確保
  nil->prev = nil;
  nil->next = nil;
}

void insert(int key) { // リスト先頭(番兵直後)にNodeを追加
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key; // x.keyにkeyを代入
  x->next = nil->next; // 元リスト先頭をxのnextにする
  nil->next->prev = x; // nilのnext(元リスト先頭)のprevをxにする
  nil->next = x; 
  x->prev = nil;
}

Node* listSearch(int key) { //検索
  Node *cur = nil->next; //返却用Node作成 & リスト先頭から順にチェック
  while(cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void deleteNode(Node *t) { //指定Nodeを削除
  if(t == nil) return; // tが番兵の場合は削除しない
  t->prev->next = t->next; //削除するNodeの前後を修正する
  t->next->prev = t->prev;
  free(t); //削除した分のNodeのメモリを解放
}

void deleteFirst() {
  deleteNode(nil->next);
}

void deleteLast() {
  deleteNode(nil->prev);
}

void deleteKey(int key) {
  deleteNode(listSearch(key)); //検索して該当Nodeを削除
}

void printList() {
  Node *cur = nil->next;
  while(1){
    printf("%d", cur->key);
    if(cur->next == nil) {
      printf("\n");
      break;
    }
    printf(" ");
    cur = cur->next;
  }
}

int main() {
  int n, key;
  string str;
  int size = 0;
  scanf("%d\n", &n);
  init(); // リスト作成(初期化)
  for(int i = 0; i < n; i++){
    cin >> str;
    if(str == "insert" || str == "delete") {
      scanf("%d\n", &key);
      if(str == "insert") insert(key);
      else deleteKey(key);
    } else if(str == "deleteFirst") {
      deleteFirst();
    } else {
      deleteLast();
    }
  }
  
  printList();
}