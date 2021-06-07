#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, sum = 0, check;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    check = 0;
    if(i % 10 == 7 || i % 8 == 7) {
      sum++;
      continue;
    }
    
    int j = i;
    while(j >= 10) {
      j /= 10;
      if(j % 10 == 7) {
        sum++;
        check = 1;
        break;
      }
    }
    if(check) continue;
    
    j = i;
    while(j >= 8) {
      j /= 8;
      if(j % 8 == 7) {
        sum++;
        break;
      }
    }
  }
  int ans = n - sum;
  printf("%d\n", ans);
}