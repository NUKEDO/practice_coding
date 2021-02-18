// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(8);
  double x1, y1, x2, y2, x, y, measure;
  cin >> x1 >> y1 >> x2 >> y2;
  
  x = (x2- x1);
  x *= x;
  y = (y2 -y1);
  y *= y;
  measure = sqrt(x + y);
  cout << measure << endl;
}