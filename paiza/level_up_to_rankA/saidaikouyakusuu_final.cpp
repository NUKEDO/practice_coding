#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b;
  scanf("%lld %lld\n", &a, &b);
  if(a < b) swap(a, b); // a > b で設計
  while(a % b != 0) { // 最終的にbが最大公約数になる
    a = a % b;
    if(a < b) swap(a, b);
  }
  printf("%lld\n", b);
}