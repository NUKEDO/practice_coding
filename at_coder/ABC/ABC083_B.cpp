#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, sum = 0, num, total;
  scanf("%d %d %d", &N, &A, &B);
  for (int i = 1; i <= N; i++) {
    num = i;
    total = 0;
    while(num > 0) {
      total += num % 10;
      num /= 10;
    }
    if(total >= A && total <= B) {
      sum += i;
    }
  }
  printf("%d\n", sum);
}