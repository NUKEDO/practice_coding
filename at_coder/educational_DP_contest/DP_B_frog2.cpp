// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  scanf("%d %d\n", &n, &k);
  vector<int> h(n), A(n, INT_MAX);
  for(int i = 0; i < n; i++) {
    scanf("%d", &h.at(i));
  }
  
  A.at(0) = 0;
  for(int i = 1; i < n; i++) {
    if(i < k) {
      A.at(i) = abs( h.at(i) - h.at(0) );
      continue;
    }
    
    for(int j = 1; j <= k ; j++) {
      A.at(i) = min(A.at(i), A.at(i - j) + abs(h.at(i) - h.at(i - j)) );
    }
  }
  
  printf("%d\n", A.at(n - 1));
}