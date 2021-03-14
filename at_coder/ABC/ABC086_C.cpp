#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum, time;
  string ans = "Yes";
  scanf("%d\n", &N);
  vector<int> t(N + 1, 0), x(N + 1, 0), y(N + 1, 0); 
  for(int i = 1; i < N + 1; i++) {
    scanf("%d %d %d\n", &t.at(i), &x.at(i), &y.at(i));
    sum = abs(x.at(i) - x.at(i - 1)) + abs(y.at(i) - y.at(i - 1));
    time = t.at(i) - t.at(i - 1);
    if( time < sum || time % 2 != sum % 2) {
      ans = "No";
      break;
    }
  }
  printf("%s\n", ans.c_str());
}