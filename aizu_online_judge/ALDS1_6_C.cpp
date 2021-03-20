// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_C&lang=ja
// 螺旋本、螺旋本を参考に作成した1_5_Bと1_6_Bの解答を参考に作成

#include <bits/stdc++.h>
using namespace std;

int n;

struct Card{
  char suit;
  int value;
};

int partition(vector<Card> &A, int p, int r) {
  int base = A.at(r).value;
  Card save;
  int q = p;
  for(int j = p; j < r; j++) {
    if(A.at(j).value <= base) {
      save = A.at(q);
      A.at(q) = A.at(j);
      A.at(j) = save;
      q++;
    }
  }
  //添字q番目に基準となる最後の数を入れる
  save = A.at(q);
  A.at(q) = A.at(r);
  A.at(r) = save;
  
  return q;
}

void quickSort(vector<Card> &A, int p, int r) {
  int q;
  if(p < r) {
    q = partition(A, p, r); //q番目の位置は正しいのでその前後をソートする
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

void merge(vector<Card> &B, int left, int mid, int right) {
  int n1 = mid - left, n2 = right - mid;
  vector<Card> L(n1 + 1), R(n2 + 1);
  for(int i = 0; i < n1; i++) {
    L.at(i) = B.at(left + i);
  }      
  for(int i = 0; i < n2; i++) {
    R.at(i) = B.at(mid + i);
  }
  L.at(n1).value = INT_MAX;
  R.at(n2).value = INT_MAX;
  int i = 0;
  int j = 0;
  for(int k = left; k < right; k++) {
    if( L.at(i).value <= R.at(j).value ){
      B.at(k) = L.at(i);
      i = i + 1;
    } else { 
      B.at(k) = R.at(j);
      j = j + 1;
    }
  }
}

void mergeSort(vector<Card> &B, int left, int right) {
  int mid;
  if(right - left >= 2) {
    mid = (left + right) / 2;
    mergeSort(B, left, mid);
    mergeSort(B, mid, right);
    merge(B, left, mid, right);
  }
}

int main() {
  scanf("%d\n", &n);
  vector<Card> A(n), B(n); //quickSort用のA、mergeSort用のB
  for(int i= 0; i < n; i++) {
    scanf("%c %d\n", &A.at(i).suit, &A.at(i).value);
    B.at(i).suit = A.at(i).suit;
    B.at(i).value = A.at(i).value;
  }
  quickSort(A, 0, n - 1);
  mergeSort(B, 0, n);
  
  string ans = "Stable";
  for(int i = 0; i < n; i++) {
    if(A.at(i).suit != B.at(i).suit) {
      ans = "Not stable";
      break;
    }
  }
  printf("%s\n", ans.c_str());
  
  for(int i = 0; i < n; i++) {
    printf("%c %d\n", A.at(i).suit, A.at(i).value);
  }
}