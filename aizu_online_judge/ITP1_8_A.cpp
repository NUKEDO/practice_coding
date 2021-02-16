// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  getline(cin, str); // スペースで入力を区切られないようにする
  
  for (int i = 0; i < str.size(); i++) {
    if(str.at(i) >= 'A' && str.at(i) <= 'Z') {
      cout << (char)(str.at(i) - ('A' - 'a'));
    } else if(str.at(i) >= 'a' && str.at(i) <= 'z') {
      cout << (char)(str.at(i) + ('A' - 'a'));
    } else {
      cout << str.at(i);
    }
  }

  /* for内の別解
  
  for (int i = 0; i < str.size(); i++) {
    if(str.at(i) >= 'A' && str.at(i) <= 'Z') {
      cout << (char)tolower(str.at(i));
    } else if(str.at(i) >= 'a' && str.at(i) <= 'z') {
      cout << (char)toupper(str.at(i));
    } else {
      cout << str.at(i);
    }
  }

  */

  cout << endl;
}