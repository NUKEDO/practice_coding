#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x1, y1, x2, y2, ans;
  scanf("%d %d\n%d %d\n", &x1, &y1, &x2, &y2);
  int x = x2 - x1, y = y2 - y1;
  if(x == 0 && y == 0) ans = 0;
  else if(abs(x) + abs(y) <= 3) ans = 1;
  else if(abs(x) - abs(y) == 0) ans = 1;
  else if((abs(x) + abs(y)) % 2 == 0) ans = 2;
  else if(abs(x) + abs(y) <= 6) ans = 2;
  else if(abs(abs(x) - abs(y)) <= 3) ans = 2;
  else ans = 3;
  printf("%d\n", ans);
}