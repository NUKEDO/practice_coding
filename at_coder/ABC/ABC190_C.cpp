#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d\n", &n, &m);
  vector<int> a(m), b(m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d\n", &a.at(i), &b.at(i));
  }
  scanf("%d\n", &k);
  vector<int> c(k), d(k);
  for(int i = 0; i < k; i++) {
    scanf("%d %d\n", &c.at(i), &d.at(i));
  }
  
  int cnt, ans = 0;
  for(int bit = 0; bit < (1 << k); bit++) { //  0 <= bit < 2^k 
    cnt = 0;
    vector<int> dish(n + 1, 0);
    for(int i = 0; i < k; i++) {
      if(bit & (1 << i)) dish.at(c.at(i)) = 1;
      else dish.at(d.at(i)) = 1;
    }
    
    for(int i = 0; i < m; i++) {
      if(dish.at(a.at(i)) == 1 && dish.at(b.at(i)) == 1) cnt++;
    }
    
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
}