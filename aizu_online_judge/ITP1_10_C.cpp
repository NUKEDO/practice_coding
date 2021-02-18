// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_C&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(8);
  int n, a;
  double sum, ave, diffe;
  
  cin >> n;
  vector<int> s;
  while (n != 0) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      s.push_back(a);
      sum += s.at(i);
    }
    ave = sum / n;
  
    sum = 0;
    for(int i = 0; i < n; i++) {
      diffe = s.at(i) - ave;
      diffe *= diffe;
      sum += diffe;
    }
    sum /= n;
    sum = sqrt(sum);
  
    cout << sum << endl;
  
    for (int i = 0; i < n; i++) {
      s.pop_back();
    }
    cin >> n;
  }
}
