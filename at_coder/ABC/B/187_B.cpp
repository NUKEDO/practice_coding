// https://atcoder.jp/contests/abc187/tasks/abc187_b

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<double>> XY(N, vector<double> (2));
  for (int i = 0; i < N; i++) {
    cin >> XY.at(i).at(0) >> XY.at(i).at(1);
  }
  
  int sum = 0;
  double cal;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i <= j) {
        continue;
      }
      cal = (XY.at(i).at(1) - XY.at(j).at(1)) / (XY.at(i).at(0) - XY.at(j).at(0));
      if (cal <= 1 && cal >= -1) {
        sum += 1;
      }
    }
  }

  cout << sum << endl;
  
}