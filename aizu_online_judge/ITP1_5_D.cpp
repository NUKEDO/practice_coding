// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_5_D&lang=ja
// もっと良い書き方があったのかもしれないので
// 「3で割れる数と3のつく数字を出力するプログラム」をgotoを使用せずに書く

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  for (int i = 0; i < a; i++) {
    int x = i + 1;
    if (x % 3 == 0) {
      cout << " " << x;
    } else {
      while (x > 0) {
        if (x % 10 == 3) {
          cout << " " << i + 1;
          break;
        }
        x /= 10;
      }
    }
  }
  cout << endl;
}