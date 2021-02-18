// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

struct Dice {
  vector<int> number;
  int save;
  
  void set(vector<int> num) {
    for (int i = 0; i < 6; i++) {
      number.push_back(num.at(i));
    }
  }
  
  int surface(int i) {
    return number.at(i);
  }
  
  void roll(string str) {
    for (int i = 0; i < str.size(); i++) {
      if (str.at(i) == 'N') {
        save = number.at(0);
        number.at(0) = number.at(1);
        number.at(1) = number.at(5);
        number.at(5) = number.at(4);
        number.at(4) = save;
      } else if (str.at(i) == 'S') {
        save = number.at(0);
        number.at(0) = number.at(4);
        number.at(4) = number.at(5);
        number.at(5) = number.at(1);
        number.at(1) = save;
      } else if (str.at(i) == 'E') {
        save = number.at(0);
        number.at(0) = number.at(3);
        number.at(3) = number.at(5);
        number.at(5) = number.at(2);
        number.at(2) = save;
        
      } else if (str.at(i) == 'W') {
        save = number.at(0);
        number.at(0) = number.at(2);
        number.at(2) = number.at(5);
        number.at(5) = number.at(3);
        number.at(3) = save;
      }
    }
  }
};
  
int main() {
  string direction;
  vector<int> num(6);
  for (int i = 0; i < 6; i++) {
    cin >> num.at(i);
  }
  
  // オブジェクト宣言
  Dice dice;
  
  // 数字貼り付け
  dice.set(num);
  
  // サイコロを命令された方向に転がす
  cin >> direction;
  dice.roll(direction);
  
  // 上部の数字を出力する
  cout << dice.surface(0) << endl;
}