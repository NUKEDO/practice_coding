#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, a, b, sum_A = 0, sum_T = 0, cnt = 0;
  scanf("%lld\n", &n);
  vector<pair<ll, ll> > v;
  for(int i = 0; i < n; i++) {
    scanf("%lld %lld\n", &a, &b);
    sum_A += a; //演説0ならsum_A票を得票される
    pair<ll, ll> p = make_pair(a + a + b, b); //a = (p.first - p.second) / 2, 2a+b=縮まる票数
    v.push_back(p);
  }
  
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end()); //firstの大きい順
  for(int i = 0; i < n; i++) {
    a = (v.at(i).first - v.at(i).second) / 2;
    sum_A -= a;
    sum_T += a + v.at(i).second; // sum_T += a + b
    cnt++;
    if(sum_T > sum_A) break;
  }
  
  printf("%lld\n", cnt);
}