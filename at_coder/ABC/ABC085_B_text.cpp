#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, num;
  scanf("%d\n", &N);
  set<int> s;
  for(int i = 0; i < N; i++) {
    scanf("%d\n", &num);
    s.insert(num);
  }
  printf("%d\n", s.size());
}