#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void bubbleSort(vector<int> &A, int n) {
  for(int i = 0; i < n; i++) { 
    for(int j = n - 1; j >= i + 1; j--) {
      if(A.at(j) < A.at(j - 1)) {
        swap(A.at(j), A.at(j - 1));
        ans++;
      }
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
  
  bubbleSort(A, n);
  
  printA(A);
  printf("%d\n", ans);
}