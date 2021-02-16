// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_C&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c, sum_h, sum_w, sum_all = 0;  
  cin >> r >> c;
  vector<vector<int>> num(r, vector<int>(c));
  
  for(int i = 0; i < r; i++) {
    sum_w = 0;
    for(int j = 0; j < c; j++) {
      cin >> num.at(i).at(j);
      cout << num.at(i).at(j) << " ";
      sum_w += num.at(i).at(j);
      sum_all += num.at(i).at(j);
      if(j == c - 1) {
        cout << sum_w << endl;
      }
    }
  }
  
  for(int j = 0; j < c; j++) {
    sum_h = 0;
    for(int i = 0; i < r; i++) {
      sum_h += num.at(i).at(j);
    }
    cout << sum_h << " ";
    if(j == c - 1) {
      cout << sum_all << endl;
    }
  }
}
