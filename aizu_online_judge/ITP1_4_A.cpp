// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(5);
  int a, b;
  cin >> a >> b;
  double c = (double)a / (double)b ;
  cout << a / b << " " << a % b << " " << c << endl;
}