#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, r;
  scanf("%lld\n", &n);
  r = sqrt(n);
  string ans = "YES";
  if(n <= 1 || n % 2 == 0) ans = "NO";
  else {
    for(int i = 3; i <= r; i += 2) {
      if(n % i == 0) {
        ans = "NO";
        break;
      }
    }
  }
  printf("%s\n", ans.c_str());
}