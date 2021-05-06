// 挿入ソートで検索して出てくる画像のみを参考に作成

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &A, int i) {
  for(int j = i - 1; j >= 0; j--) {
    if(A.at(i) < A.at(j)) {
      swap(A.at(i), A.at(j));
      i--;
    } else {
      return;
    }
  }
}

void printA(vector<int> A) {
  for(int i = 0; i < A.size(); i++) {
    if(i) printf(" ");
    printf("%d", A.at(i));
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &A.at(i));
  }
  for(int i = 0; i < n; i++) {
    insertionSort(A, i); //A.at(0)からA.at(i)までをソート
    printA(A);
  }
}