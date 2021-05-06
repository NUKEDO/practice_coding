#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, num;
  scanf("%d %d", &x, &y);
  do {
    if(x > y) swap(x, y); // x < y にする
    num = y % x;
    y = num;
  } while(num != 0); //余りが0でない限り実行
  
  printf("%d\n", x);
}