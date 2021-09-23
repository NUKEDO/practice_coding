// https://atcoder.jp/contests/dp/tasks/dp_h
// https://kenkoooo.com/atcoder/#/contest/show/a7a90ea6-4e26-4aaa-bcba-eb6322a6ce22

#include <bits/stdc++.h>
using namespace std;
#define A 1000000007

void printPic(vector<vector<int> > v) {
  for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v.at(i).size(); j++) {
      if(j) printf(" ");
      printf("%d", v.at(i).at(j));
    }
    printf("\n");
  }
}

int main() {
  int h, w;
  scanf("%d %d\n", &h, &w);
  vector<string> route(h);
  for(int i = 0; i < h; i++) {
    cin >> route.at(i);
  }
  
  vector<vector<int> > dp(h, vector<int>(w, 0));
  int check = 0;
  for(int i = 0; i < w; i++) {
    if(check == 1) {
      dp.at(0).at(i) = 0;
    } else if(route.at(0).at(i) == '#') {
      check = 1;
      dp.at(0).at(i) = 0;
    } else {
      dp.at(0).at(i) = 1;
    }
  }
  check = 0;
  for(int i = 0; i < h; i++) {
    if(check == 1) {
      dp.at(i).at(0) = 0;
    } else if(route.at(i).at(0) == '#') {
      check = 1;
      dp.at(i).at(0) = 0;
    } else {
      dp.at(i).at(0) = 1;
    }
  }
  
  for(int i = 1; i < h; i++) {
    for(int j = 1; j < w; j++) {
      if(route.at(i).at(j) == '#') dp.at(i).at(j) = 0;
      else dp.at(i).at(j) = (dp.at(i - 1).at(j) + dp.at(i).at(j - 1)) % A;
    }
  }
  //printPic(dp);
  
  printf("%d\n", dp.at(h - 1).at(w - 1));
}