#include <bits/stdc++.h>
using namespace std;

int main() {
  int num, money;
  scanf("%d %d", &num, &money);
  
  int a = -1, b = -1, c = -1; // aが１万円札の枚数
  if(money <= 10000 * num && money >= 1000 * num && money % 1000 == 0) {
    int max_a = money / 10000, max_b = money / 5000;
    int check = 0;
    for(int i = 0; i <= max_a; i++) {
      for(int j = 0; j <= max_b - i; j++) {
        int k = (money - 10000 * i - 5000 * j) / 1000;
        if(k < 0) continue;
        if(i + j + k == num) {
          a = i;
          b = j;
          c = k;
          check = 1;
          break;
        }
      }
      if(check == 1) break;
    }
  }
  
  printf("%d %d %d\n", a, b, c);
}