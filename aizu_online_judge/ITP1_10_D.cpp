// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(8);
  int n, max = 0, x;
  double sum = 0, sum_2 = 0, sum_3 = 0;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> b.at(i);
    x = a.at(i) - b.at(i);
    c.at(i) = abs(x);
    if(c.at(i) > max) {
      max = c.at(i); // P=無限
    }
    sum += c.at(i); // P=1
    sum_2 += pow(c.at(i), 2);
    sum_3 += pow(c.at(i), 3);
  }
  
  sum_2 = pow(sum_2, 1.0 / 2.0);
  sum_3 = pow(sum_3, 1.0 / 3.0);
  
  cout << sum << endl << sum_2 << endl << sum_3 << endl << (double)max << endl;
}
