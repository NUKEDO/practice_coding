//TLEになる

#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int n, m, minv = INT_MAX, maxv = 0;
vector<int> num(MAX);

void minLong() {
  int sum, cnt;
  for(int i = 0; i < n; i++) {
    sum = 0;
    cnt = 0;
    for(int j = i; j < n; j++) {
      sum += num.at(j);
      cnt++;
      if(sum >= m) break;
      if(j == n - 1) cnt = INT_MAX;
    }
    minv = min(minv, cnt);
  }
  if(minv == INT_MAX) minv = -1;
}

void maxLong() {
  int sum, cnt, check = 0;
  for(int i = 0; i < n; i++) {
    sum = 0;
    cnt = 0;
    for(int j = i; j < n; j++) {
      sum += num.at(j);
      if(sum >= m) break;
      cnt++;
      if(j == n - 1) check = 1; // 一番最後まで数えていた場合
    }
    maxv = max(maxv, cnt);
    if(check) return;
  }
}

int main() {
  scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num.at(i));
  }
  
  //minLong();
  //printf("%d\n", minv);
  
  maxLong();
  printf("%d\n", maxv);
}