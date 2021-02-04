// https://atcoder.jp/contests/abc186/tasks/abc186_b

#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, min, sum = 0;
  cin >> H >> W;
  vector<vector<int>> block(H, vector<int> (W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> block.at(i).at(j);
      if (i == 0 && j == 0) {
        min = block.at(i).at(j);
      }
      if (min > block.at(i).at(j)) {
        min = block.at(i).at(j);
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (block.at(i).at(j) > min) {
        sum += block.at(i).at(j) - min;
      }
    }
  }
  
  cout << sum << endl;
  
}