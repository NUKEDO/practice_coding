#include <bits/stdc++.h>
using namespace std;

int sum_range(int a, int b) {
  /*
  a=3 b=7の時
  y = 3~7
    = 3 + 4~7
    = 3 + 4 + 5~7
  */
  
  if (a == b) {
    return a;
  }
  
  int s = sum_range(a + 1, b);
  return a + s;
}
  
int main() {
  int a, b;
  cin >> a >> b;
  int ans = sum_range(a, b);
  
  cout << ans << endl;
}
