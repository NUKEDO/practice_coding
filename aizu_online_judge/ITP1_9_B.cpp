// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_B&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int m, h, num;
  cin >> str;
  while (str != "-") {
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> h;
      for(int j = 0; j < h; j++) {
        // 宣言された数だけ文字を末尾に移動 h=3,str="abcde" => str="abcdeabc" 
        str.push_back(str.at(j));
      }
      num = str.size(); // num=8
      for(int j = 0; j < num - h; j++) {
        // 文字の位置をトップに移動 "abcdeabc" => "deabcabc"
        str.at(j) = str.at(j + h);
      }
      for(int j = 0; j < h; j++) {
        // 増えた文字数分削除 "deabcabc" => "deabc"
        str.pop_back();
      }
    }
    cout << str << endl;
    cin >> str;
  }
}