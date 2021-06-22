// https://twitter.com/kyopro_dekomor2/status/1406890339886006275?s=20
// https://kenkoooo.com/atcoder/#/contest/show/a7a90ea6-4e26-4aaa-bcba-eb6322a6ce22

// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> v) {
  for(int i = 0; i < v.size(); i++) {
    if(i) printf(" ");
    printf("%d", v.at(i));
  }
  printf("\n");
}

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
  int n;
  scanf("%d\n", &n);
  vector<vector<int> > v(n, vector<int>(3, -1)), dp(n, vector<int>(3, -1));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      scanf("%d", &v.at(i).at(j));
    }
  }
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      if(i == 0) {
        dp.at(i).at(j) = v.at(i).at(j);
        continue;
      }
      
      for(int k = 0; k < 3; k++) {
        if(j != k) {
          dp.at(i).at(j) = max(dp.at(i).at(j),
                               dp.at(i - 1).at(k) + v.at(i).at(j));
        }
      }
    }
  }
  
  //printPic(dp);
  printf("%d\n", max(dp.at(n - 1).at(0),
                     max( dp.at(n - 1).at(1), dp.at(n - 1).at(2) )));
}