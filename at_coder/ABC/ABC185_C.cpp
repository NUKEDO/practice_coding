#include <bits/stdc++.h>
using namespace std;
#define N 199

vector<vector<long long> > ncr(N + 1, vector<long long>(N + 1, 0));

void ncrNeutral() {
  for(int i = 0; i < N; i++) {
    ncr.at(i).at(0) = 1;
    ncr.at(i).at(i) = 1;
  }
}

void makeNCR(long long n, long long r) {
  for(int i = 2; i <= n; i++) {
    if(ncr.at(i).at(1) != 0) continue;
    for(int j = 1; j < i; j++) {
      ncr.at(i).at(j) = ncr.at(i - 1).at(j - 1) + ncr.at(i - 1).at(j);
    }
  }
}

long long comb(long long n, long long r) {
  if(ncr.at(n).at(r) == 0) {
    if(ncr.at(0).at(0) == 0) ncrNeutral();
    makeNCR(n, r);
  }
  return ncr.at(n).at(r);
}

int main() {
  long long n;
  scanf("%lld\n", &n);
  long long ans = comb(n - 1, 11);
  printf("%lld\n", ans);
}