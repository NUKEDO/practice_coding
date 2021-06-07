#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  long long sum_all = 0;
  vector<long long> v(n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &v.at(i));
    sum_all += v.at(i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  long long sum = 0;
  for(int i = 0; i < n - 1; i++) {
    sum += v.at(i) * (n - i - 1);
    sum_all -= v.at(i);
    sum -= sum_all;
  }
  printf("%lld\n", sum);
}