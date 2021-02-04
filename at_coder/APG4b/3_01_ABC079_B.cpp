// https://atcoder.jp/contests/apg4b/tasks/APG4b_y
// https://atcoder.jp/contests/abc079/tasks/abc079_b

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  
  int64_t a = 2, b = 1, c = 1; //N=1のときc=1
  
  for (int i = 0; i < N - 1 ; i++) { //N=1のとき実行されない
    c = a + b;
    a = b;
    b = c;
  }
  
  printf("%ld\n", c);
}