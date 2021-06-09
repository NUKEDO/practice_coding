#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, num;
  scanf("%d %d\n", &n, &m);
  priority_queue<int> pq;
  for(int i = 0; i < m; i++) {
    scanf("%d", &num);
    pq.push(num - 1); // 0 ~ n-1
  }
  pq.push(-1);
  
  vector<int> v;
  int a = n, b;
  int min_l = INT_MAX;
  while(pq.size() > 0) {
    b = pq.top();
    pq.pop();
    int d = a - b - 1; // distance
    v.push_back(d);
    if(d != 0) min_l = min(min_l, a - b - 1);
    a = b;
  }
  int cnt = 0;
  for(int i = 0; i < v.size(); i++) {
    if(v.at(i) % min_l == 0) cnt += v.at(i) / min_l; 
    else cnt += v.at(i) / min_l + 1;
  }
  printf("%d\n", cnt);
}