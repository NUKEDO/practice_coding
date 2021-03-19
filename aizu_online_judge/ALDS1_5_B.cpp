// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_B&lang=ja

#include <bits/stdc++.h>
using namespace std;

int sum = 0;

void merge(vector<int> &A, int left, int mid, int right) {
  int n1 = mid - left, n2 = right - mid;
  vector<int> L(n1 + 1), R(n2 + 1);
  for(int i = 0; i < n1; i++) {
    L.at(i) = A.at(left + i);
  }      
  for(int i = 0; i < n2; i++) {
    R.at(i) = A.at(mid + i);
  }
  L.at(n1) = INT_MAX;
  R.at(n2) = INT_MAX;
  int i = 0;
  int j = 0;
  for(int k = left; k < right; k++) {
    if( L.at(i) <= R.at(j) ){
      A.at(k) = L.at(i);
      i = i + 1;
    } else { 
      A.at(k) = R.at(j);
      j = j + 1;
    }
    sum++;
  }
}

void mergeSort(vector<int> &A, int left, int right) {
  if (right - left >= 2) { // 3個以上の連続した配列だった場合
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  vector<int> S(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &S.at(i));
  }
  mergeSort(S, 0, n);
  for(int i = 0; i < n; i++) {
    cout << S.at(i);
    (i == n - 1) ? cout << endl : cout << " ";
  }
  cout << sum << endl;
}