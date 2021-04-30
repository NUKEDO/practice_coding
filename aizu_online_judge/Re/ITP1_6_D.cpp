#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  vector<vector<int> > A(h, vector<int>(w));
  vector<int> B(w), ans(h);
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      scanf("%d", &A.at(i).at(j));
    }
  }
  for(int i = 0; i < w; i++) {
    scanf("%d", &B.at(i));
  }
  
  for(int i = 0; i < h; i++) {
    int sum = 0;
    for(int j = 0; j < w; j++) {
      sum += A.at(i).at(j) * B.at(j);
    }
    ans.at(i) = sum;
  }
  
  for(int i = 0; i < h; i++) {
    printf("%d\n", ans.at(i));
  }
}