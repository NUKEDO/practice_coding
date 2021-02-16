// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, p, search = "", ans = "No";
  cin >> s >> p;
  s += s;
  
  for (int i = 0; i < s.size() / 2; i++) {
    if (s.at(i) == p.at(0)) {
      for (int j = 0; j < p.size(); j++) {
        search.push_back(s.at(i + j));
      }
      if (search == p) {
        ans = "Yes";
        break;
      } else {
        search = "";
      }
    }
  }    

  cout << ans << endl;
}
