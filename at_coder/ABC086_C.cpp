#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, t, x, y, sum, time;
  scanf("%d\n", &N);
  vector<int> now(N + 1), pos_x(N + 1), pos_y(N + 1);
  now.at(0) = 0;
  pos_x.at(0) = 0;
  pos_y.at(0) = 0;
  string ans = "Yes";
  for(int i = 1; i < N + 1; i++) {
    scanf("%d %d %d\n", &t, &x, &y);
    now.at(i) = t;
    pos_x.at(i) = x;
    pos_y.at(i) = y;
    sum = abs(pos_x.at(i) - pos_x.at(i - 1)) + abs(pos_y.at(i) - pos_y.at(i - 1));
    time = now.at(i) - now.at(i - 1);
    if(time < sum || time % 2 != sum % 2) {
      ans = "No";
      break;
    }
  }
  printf("%s\n", ans.c_str());
}