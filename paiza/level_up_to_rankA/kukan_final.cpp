#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, minv = INT_MAX;
  long long k;
  scanf("%d %lld\n", &n, &k);
  vector<long long> num(n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &num.at(i));
  }
  
  long long sum = 0;
  int j, cnt = 0;
  for(int i = 0; i < n; i++) {
    if(num.at(i) == 0) {
      sum = 0;
      cnt = 0;
      continue;
    }
    
    if(sum == 0) {
      j = i;
      sum = num.at(i);
      cnt = 1;
    } else {
      sum *= num.at(i);
      cnt++;
    }
    
    while(j < i && sum >= k) {
      if(sum / num.at(j) >= k) {
        cnt--;
        sum /= num.at(j);
        j++;
      } else break;
    }
    
    if(sum >= k) minv = min(minv, cnt);
  }
  
  printf("%d\n", minv);
}