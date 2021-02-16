// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a;
  cin >> n >> m;
  a = n * m;
  vector<int> A(a), B(m), ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A.at(i * m + j);
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> B.at(i);
  }
  
  int x, sum = 0;
  for (int i = 0; i < a; i++) {
    x = i % m;
    sum += A.at(i) * B.at(x);
    if (i % m == m - 1) {
      x = i / m;
      ans.at(x) = sum;
      sum = 0;
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << ans.at(i) << endl;  
  } 
}