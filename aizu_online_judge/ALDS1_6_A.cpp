// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  vector<int> A(n), B(n), C(10001, 0); // Bがソート後
  for(int i = 0; i < n; i++) {
    scanf("%d", &A.at(i));
    C.at( A.at(i) )++;
  }
  
  for(int i = 0; i < 10000; i++) {
    C.at(i + 1) += C.at(i);
  }
  
  for(int i = n - 1; i >= 0; i--) {
    B.at(C.at ( A.at(i) ) - 1) = A.at(i);
    C.at(A.at(i))--;
  }
  
  for(int i = 0; i < n; i++) {
    if(i) printf(" ");
    printf("%d", B.at(i));
  }
  printf("\n");
}