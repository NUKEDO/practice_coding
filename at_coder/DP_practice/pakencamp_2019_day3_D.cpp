// https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_d
// https://kenkoooo.com/atcoder/#/contest/show/a7a90ea6-4e26-4aaa-bcba-eb6322a6ce22

#include <bits/stdc++.h>
using namespace std;

void printPic(vector<string> v) {
  for(int i = 0; i < 5; i++) {
    printf("%s\n", v.at(i).c_str());
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  vector<string> v(5);
  for(int i = 0; i < 5; i++) {
    cin >> v.at(i);
  }
  //printPic(v);
  
  vector<vector<int> > dp(n, vector<int>(3, 0)); //青白赤
  for(int i = 0; i < n; i++) {
    string color = "BWR";
    for(int j = 0; j < 3; j++) {
      int cnt = 0;
      for(int k = 0; k < 5; k++) {
        if(color.at(j) != v.at(k).at(i)) {
          cnt++;
        }
      }
      if(i == 0) {
        dp.at(i).at(j) = cnt;
      } else {
        int min_dp = INT_MAX;
        for(int k = 0; k < 3; k++) {
          if(j == k) continue;
          min_dp = min(min_dp, dp.at(i - 1).at(k));
        }
        dp.at(i).at(j) = cnt + min_dp;
      }
    }
  }
  int ans = INT_MAX;
  for(int i = 0; i < 3; i++) {
    ans = min(ans, dp.at(n - 1).at(i));
  }
  
  printf("%d\n", ans);
}