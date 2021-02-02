// https://atcoder.jp/contests/abc188/tasks/abc188_b

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  
  int sum = 0, cal = 0;
  for (int i = 0; i < N; i++) {
    cal = A.at(i) * B.at(i);
    sum += cal;
  }
  
  string str;
  if (sum == 0) {
    str = "Yes";
  }
  else {
    str = "No";
  }
  
  cout << str << endl;
  
}