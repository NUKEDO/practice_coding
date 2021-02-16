// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  // 指数表示(3億を3e+08と表示)されないためにsetprecisionを設定
  cout << setprecision(11);
  int N, a, min, max;
  // 数字が±100万、入力個数が1万なのでsumが20億を超える可能性がある
  double sum = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    sum += a;
    if (i == 0 || a < min) {
      min = a;
    }
    if (i == 0 || a > max) {
      max = a;
    }
  }

  cout << (int)min << " " << (int)max << " " << (double)sum << endl;
}