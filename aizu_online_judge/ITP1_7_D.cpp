// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(0);
  int n, m, l, num;
  double prod, sum;
  cin >> n >> m >> l;
  vector<vector<int>> A(n, vector<int>(m)), B(m, vector<int>(l));
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> A.at(i).at(j);
    }
  }
  
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < l; j++) {
      cin >> B.at(i).at(j);
    }
  }
  
  for(int i = 0; i < n; i++) {
    num = 0;
    for(int j = 0; j < l; j++) {
      sum = 0;
      for(int k = 0; k < m; k++) {
        prod = A.at(i).at(k) * B.at(k).at(j);
        sum += prod;
      }
      cout << sum;
      
      num++;
      if(num != l) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
  }
  
}