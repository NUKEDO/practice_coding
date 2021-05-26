#include <bits/stdc++.h>
using namespace std;

vector<int> num = {1, 0, -1};

int main() {
  int n, k;
  scanf("%d %d\n", &n, &k);
  n--;
  k--;
  n %= 3;
  k %= 3;
  if(n > k) k += 3;
  
  int sum = 0;
  for(int i = n; i <= k; i++) {
    sum += num.at(i%3);
  }
  printf("%d\n", sum);
}