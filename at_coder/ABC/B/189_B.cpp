// https://atcoder.jp/contests/abc189/tasks/abc189_b

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<vector<int>> alc(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> alc.at(i).at(0) >> alc.at(i).at(1);
  }
  
  int sum = 0, having = 0, count = 0;
  for (int i = 0; i < N; i++) {
    having = alc.at(i).at(0) * alc.at(i).at(1);
    sum += having;
    count += 1;
    if (sum > X * 100) {
      break;
    }
  }
  
  if (count == N && sum <= X * 100) {
    count = -1;
  }
  
  cout << count << endl;
  
}