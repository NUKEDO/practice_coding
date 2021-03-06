#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A = 0, B = 0;
  scanf("%d\n", &N);
  vector<int> num(N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &num.at(i));
  }
  sort(num.begin(), num.end());
  reverse(num.begin(), num.end());
  for(int i = 0; i < N; i += 2) {
    A += num.at(i);
  }
  for(int i = 1; i < N; i += 2) {
    B += num.at(i);
  }
  printf("%d\n", A - B);
}