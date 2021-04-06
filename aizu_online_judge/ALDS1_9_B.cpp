// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_B&lang=ja
// 参考 http://www.th.cs.meiji.ac.jp/assets/researches/2005/omoto/heapsort.html

#include <bits/stdc++.h>
using namespace std;

int n;

int parent(int i) {return i / 2;}
int left(int i) {return i * 2;}
int right(int i) {return i * 2 + 1;}

void maxHeapify(vector<int> &A, int u) { //入れ替えを行い、入れ替えた先で再帰する
  int l = left(u), r = right(u), save;
  if(l <= n && A.at(l) > A.at(u) && A.at(l) > A.at(r)) {
    save = A.at(u);
    A.at(u) = A.at(l);
    A.at(l) = save;
    maxHeapify(A, l);
  } else if(r <= n && A.at(r) > A.at(u) && A.at(r) > A.at(l)) {
    save = A.at(u);
    A.at(u) = A.at(r);
    A.at(r) = save;
    maxHeapify(A, r);
  }
}

void buildMaxHeap(vector<int> &A) {
  for(int H = n / 2; H >= 1; H--) {
    maxHeapify(A, H);
  }
}

void print(vector<int> A) {
  for(int i = 1; i <= n; i++) {
    printf(" %d", A.at(i));
  }
  printf("\n");
}

int main() {
  int num;
  scanf("%d\n", &n);
  vector<int> A(n + 2);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &A.at(i));
  }
  A.at(n + 1) = INT_MIN; // 右の子が空である時用
  
  buildMaxHeap(A);
  
  print(A);
}