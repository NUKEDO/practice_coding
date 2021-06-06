#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, cnt = 0;
  scanf("%lld", &n);
  n *= 2;
  long long k = sqrt(n);
  for(int i = 1; i <= k; i++) {
    if(n % i == 0) {
      if(i % 2 == 0 && (n / i) % 2 == 1) cnt++;
      else if(i % 2 == 1 && (n / i) % 2 == 0) cnt++;
    }
  }
  cnt *= 2;
  printf("%lld\n", cnt);
}