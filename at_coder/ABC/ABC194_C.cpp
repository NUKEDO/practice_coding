#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, num;
  scanf("%lld", &n);
  vector<long long> cnt(401, 0); //-200 ~ 200
  for(int i = 0; i < n; i++) {
    scanf("%lld", &num);
    cnt.at(num + 200)++;
  }
  
  long long x, sum = 0;
  for(int i = 400; i >= 1; i--) {
    for(int j = i - 1; j >= 0; j--) {
      x = (i - 200) - (j - 200);
      x *= x;
      sum += x * cnt.at(i) * cnt.at(j);
    }
  }
  printf("%lld\n", sum);
}