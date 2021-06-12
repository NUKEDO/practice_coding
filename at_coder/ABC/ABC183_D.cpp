#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, w, s, t, p;
  scanf("%lld %lld\n", &n, &w);
  vector<long long> dp(200001, 0);
  for(int i = 0; i < n; i++) {
    scanf("%lld %lld %lld\n", &s, &t, &p);
    dp.at(s) += p;
    dp.at(t) -= p;
  }
  
  long long sum = 0;
  string ans = "Yes";
  for(int i = 0; i <= 200000; i++) {
    sum += dp.at(i);
    if(sum > w) {
      ans = "No";
      break;
    }
  }
  
  printf("%s\n", ans.c_str());
}
