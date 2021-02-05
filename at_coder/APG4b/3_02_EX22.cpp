// https://atcoder.jp/contests/apg4b/tasks/APG4b_z
// https://atcoder.jp/contests/apg4b/tasks/APG4b_ca

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b;
  scanf("%d", &N);
  vector<pair<int, int>> p(N);
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    p.at(i) = make_pair(b, a);
  }
  
  sort(p.begin(), p.end());
  
  for (int i = 0; i < N; i++) {
    printf("%d %d\n", p.at(i).second, p.at(i).first);
  }
}
