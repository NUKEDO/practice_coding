// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_B&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(6);
  double r;
  cin >> r;

  // ライブラリから円周率を呼び出すこと
  // https://www.ect.niihama-nct.ac.jp/~kurihara/kurilab/programing/pi.html

  double area = r * r * M_PI; //M_PIが円周率
  double cir = 2 * r * M_PI;
  cout << area << " " << cir << endl;
}