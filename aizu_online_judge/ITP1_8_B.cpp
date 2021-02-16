// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_B&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int num, sum = 0;
  string str;
  cin >> str;
  
  while (str != "0") {
    for (int i = 0; i < str.size(); i++) {
      num = str.at(i) - '0'; // 文字を数字に変換したい場合は「文字-'0'」を行う
      sum += num;
    }
    cout << sum << endl;
    sum = 0;
    cin >> str;
  }
}
