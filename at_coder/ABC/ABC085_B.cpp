#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum = 1;
  scanf("%d\n", &N);
  vector<int> num(N);
  for(int i = 0; i < N; i++) {
    scanf("%d\n", &num.at(i));
  }
  sort(num.begin(), num.end());
  for(int i = 1; i < N; i++) {
    if( num.at(i) != num.at(i - 1) ) sum++;
  }
  printf("%d\n", sum);
}