// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_B&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(8);
  double a, b, c, S, L, h, x;
  cin >> a >> b >> c;
  
  h = b * sin(2 * M_PI * (c / 360));
  S = a * h / 2;
  x = sqrt(a * a + b * b - 2 * a * b * cos(2 * M_PI * (c / 360)));
  L = a + b + x;

  cout << S << endl << L << endl << h << endl;
}