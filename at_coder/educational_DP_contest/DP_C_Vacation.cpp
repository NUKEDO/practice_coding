// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

int main() { //計算量O(9n)
  int n;
  scanf("%d\n", &n);
  vector<vector<int> > p(n, vector<int>(3));
  for(int i = 0; i < n; i++) {
    scanf("%d %d %d\n", &p.at(i).at(0), &p.at(i).at(1), &p.at(i).at(2)); 
  }
  
  vector<vector<int> > A(n, vector<int>(3, -1));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      if(i == 0) {
        A.at(i).at(j) = p.at(i).at(j);
        continue;
      }
      
      for(int k = 0; k < 3; k++) {
        if(j != k) {
          A.at(i).at(j) = max(A.at(i).at(j), p.at(i).at(j) + A.at(i - 1).at(k));
        }
      }
    }
    // printf("i=%d, A = %d:%d:%d\n", i, A.at(i).at(0), A.at(i).at(1), A.at(i).at(2));
  }
  
  int ans = max(A.at(n - 1).at(0), max(A.at(n - 1).at(1), A.at(n - 1).at(2)) );
  printf("%d\n", ans);
}