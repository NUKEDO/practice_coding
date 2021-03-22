// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja
// 螺旋本の解説を読んで作成

#include <bits/stdc++.h>
using namespace std;

long long sum = 0;

void merge(vector<int> &A, int left, int mid, int right) {
  int n1 = mid - left, n2 = right - mid;
  vector<int> L(n1 + 1), R(n2 + 1);
  for (int i = 0; i < n1; i++) {
    L.at(i) = A.at(left + i);
  }
  for (int i = 0; i < n2; i++) {
    R.at(i) = A.at(mid + i);
  }
  L.at(n1) = INT_MAX;
  R.at(n2) = INT_MAX;
  int j = 0, k = 0, sizeL = L.size() - 1; // 番兵の分減らす
  for(int i = left; i < right; i++) {
    if(L.at(j) <= R.at(k)) {
      A.at(i) = L.at(j);
      j++;
      sizeL--;
    } else {
      A.at(i) = R.at(k);
      k++;
      sum += sizeL;
    }
  }
}

void mergeSort(vector<int> &A, int left, int right) {
  int mid;
  if(right - left >= 2) {
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &A.at(i));
  }
  
  mergeSort(A, 0, n);

  cout << sum << endl;
}