// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_C&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  char longer;
  string Tcard, Hcard;
  int n, Taro = 0, Hanako = 0, measure, j;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> Tcard >> Hcard;
    if (Tcard.size() > Hcard.size()) {
      longer = 'T';
      measure = Hcard.size();
    } else if (Tcard.size() < Hcard.size()) {
      longer = 'H';
      measure = Tcard.size();
    } else {
      longer = 'N';
      measure = Tcard.size();
    }
    
    j = 0;
    while (j < measure) {
      if (Tcard.at(j) < Hcard.at(j)) {
        Hanako += 3;
        break;
      } else if (Tcard.at(j) > Hcard.at(j)) {
        Taro += 3;
        break;
      }
      if (j == measure - 1) { // 短い側の最後の文字まで一致した時
        if (longer == 'T') { // 長い文字数側が勝利
          Taro += 3;
        } else if (longer == 'H') {
          Hanako += 3;
        } else {
          Taro += 1;
          Hanako += 1;
        }
      }
      j++;
    }
  }
  cout << Taro << " " << Hanako << endl;
}
