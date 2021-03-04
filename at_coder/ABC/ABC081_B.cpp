#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, min_num = INT_MAX, sum;
  scanf("%d\n", &N);
  vector<int> num(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &num.at(i));
    sum = 0;
    while(sum <= min_num && num.at(i) % 2 == 0){
      sum++;
      num.at(i) /= 2;
    }
    min_num = min(sum, min_num);
    if(min_num == 0) {
      break;
    }
  }
  printf("%d\n", min_num);
}