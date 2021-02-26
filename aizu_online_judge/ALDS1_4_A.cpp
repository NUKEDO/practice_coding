// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q, sum = 0;
  cin >> n;
  vector<int> S(n);
  for(int i = 0; i < n; i++) {
    cin >> S.at(i);
  }
  cin >> q;
  vector<int> T(q);
  for(int i = 0; i < q; i++) {
    cin >> T.at(i);
  }
  
  for(int i = 0; i < q; i++) {
    for(int j = 0; j < n; j++) {
      if(T.at(i) == S.at(j)) {
        sum++;
        break;
      }
    }
  }
  cout << sum << endl;
}