// https://atcoder.jp/contests/abc185/tasks/abc185_b

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  double T, now, past = 0;
  cin >> N >> M >> T;
  vector<vector<double>> time(M, vector<double> (2));
  for (int i = 0; i < M; i++) {
    cin >> time.at(i).at(0) >> time.at(i).at(1);
  }
  
  int max = N;
  string str = "Yes";
  for (int i = 0; i < M; i++) {
    // カフェ到着まで
    now = time.at(i).at(0);
    N -= now - past;
    if (N <= 0) {
      str = "No";
      break;
    }
    // カフェ滞在中
    N += time.at(i).at(1) - time.at(i).at(0);
    if (N > max) {
      N = max;
    }
    past = time.at(i).at(1);
  }
  
  // 帰宅まで
  N -= T - past;
  if (N <= 0) {
      str = "No";
  }
  
  cout << str << endl;
  
}