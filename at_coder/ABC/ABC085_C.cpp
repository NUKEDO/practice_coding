#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Y, k, total, check = 0;
  vector<int> ans(3, -1);
  scanf("%d %d\n", &N, &Y);
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= N - i; j++) {
      k = N - i - j;
      total = 10000 * i + 5000 * j + 1000 * k;
      if(total == Y) {
        ans.at(0) = i;
        ans.at(1) = j;
        ans.at(2) = k;
        check = 1;
        break;
      }
    }
    if(check == 1) {
      break;
    }
  }
  printf("%d %d %d\n", ans.at(0), ans.at(1), ans.at(2));
}