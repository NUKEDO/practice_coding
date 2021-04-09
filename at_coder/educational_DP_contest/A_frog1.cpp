// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  vector<int> h(n), A(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &h.at(i));
  }
  
  A.at(0) = 0;
  for(int i = 1; i < n; i++) {
    if(i == 1) {
      A.at(i) = abs( h.at(i) - h.at(i - 1) );
      continue;
    }
    
    A.at(i) = min( A.at(i - 2) + abs(h.at(i) - h.at(i - 2) ),
                   A.at(i - 1) + abs(h.at(i) - h.at(i - 1) ) );
  }
  
  printf("%d\n", A.at(n - 1));
}