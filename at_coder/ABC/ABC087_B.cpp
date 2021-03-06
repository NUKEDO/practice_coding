#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, sum = 0;
  scanf("%d\n%d\n%d\n%d\n", &A, &B, &C, &X);
  int total = 500 * A + 100 * B + 50 * C;
  if(total >= X) {
    for (int i = 0; i <= A; i++) {
      for (int j = 0; j <= B; j++) {
        for (int k = 0; k <= C; k++) {
          total = 500 * i + 100 * j + 50 * k;
          if(total == X) sum++;
        }
      }
    }
  }
  printf("%d\n", sum);
}