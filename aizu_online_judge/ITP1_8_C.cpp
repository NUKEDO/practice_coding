// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_C&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str = "";
  vector<int> alpha(26, 0);
  while(getline(cin, str)) { // 複数行に渡って文での入力がある場合
    for (int i = 0; i < str.size(); i++) {
      for (int j = 0; j < 26; j++) {
        if(str.at(i) == 'a' + j || str.at(i) == 'A' + j) {
          alpha.at(j) += 1;
        }
      }
    }
  }
        
  for (int i = 0; i < 26; i++) {
    cout << (char)('a' + i) << " : " << alpha.at(i) << endl;
  }
}
