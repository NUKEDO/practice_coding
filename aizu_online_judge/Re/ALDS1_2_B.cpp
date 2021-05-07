#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void selectionSort(vector<int> &A, int n) {
  for(int i = 0; i < n - 1; i++) {
    int min_A = INT_MAX, min_j;
    for(int j = i; j < n; j++) {
      if(min_A > A.at(j)) {
        min_A = A.at(j);
        min_j = j;
      }
    }
    if(i != min_j) {
      swap(A.at(i), A.at(min_j));
      ans++;
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
  
  selectionSort(A, n);
  
  printA(A);
  printf("%d\n", ans);
}