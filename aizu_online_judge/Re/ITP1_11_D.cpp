// vectorの初期化機能はc++11以降のため、c++11にて提出

#include <bits/stdc++.h>
using namespace std;

struct Dice {
  vector<int> num;
};

void diceSpin(Dice &dice) {
  int save;
  save = dice.num.at(1);
  dice.num.at(1) = dice.num.at(2);
  dice.num.at(2) = dice.num.at(4);
  dice.num.at(4) = dice.num.at(3);
  dice.num.at(3) = save;
}

void diceRoll(Dice &dice, char c) {
  int save;
  if(c == 'N') {
    save = dice.num.at(0);
    dice.num.at(0) = dice.num.at(1);
    dice.num.at(1) = dice.num.at(5);
    dice.num.at(5) = dice.num.at(4);
    dice.num.at(4) = save;
  } else if(c == 'S') {
    save = dice.num.at(0);
    dice.num.at(0) = dice.num.at(4);
    dice.num.at(4) = dice.num.at(5);
    dice.num.at(5) = dice.num.at(1);
    dice.num.at(1) = save;
  } else if(c == 'W') {
    save = dice.num.at(0);
    dice.num.at(0) = dice.num.at(2);
    dice.num.at(2) = dice.num.at(5);
    dice.num.at(5) = dice.num.at(3);
    dice.num.at(3) = save;
  } else if(c == 'E') {
    save = dice.num.at(0);
    dice.num.at(0) = dice.num.at(3);
    dice.num.at(3) = dice.num.at(5);
    dice.num.at(5) = dice.num.at(2);
    dice.num.at(2) = save;
  }
}

int searchDice(Dice dice, int num) {
  for(int i = 0; i < 6; i++) {
    if(dice.num.at(i) == num) return i;
  }
}

void setDiceTop(Dice &dice, int num) {
  int pos = searchDice(dice, num);
  if(pos == 0 || pos == 1 || pos == 4 || pos == 5) {
    for(int i = 0; i < 3; i++) {
      if(dice.num.at(0) == num) return;
      diceRoll(dice, 'N');
    }
  } else {
    for(int i = 0; i < 3; i++) {
      if(dice.num.at(0) == num) return;
      diceRoll(dice, 'W');
    }
  }
}

int diceNumCheck(Dice dice1, Dice dice2) {
  for(int i = 0; i < 6; i++) {
    if(dice1.num.at(i) != dice2.num.at(i)) return 0;
  }
  return 1;
}

string diceAllCheck(Dice dice1, Dice dice2) {
  vector<string> direction = {"", "N", "NN", "S", "NE", "NW"};
  Dice dice3;
  for(int i = 0; i < 6; i++) {
    dice3 = dice2;
    
    for(int j = 0; j < direction.at(i).size(); j++) { //上面の変更
      diceRoll(dice3, direction.at(i).at(j));
    }
    if(dice3.num.at(0) != dice1.num.at(0)) continue; // すでに不一致なら次のi
    
    
    for(int j = 0; j < 4; j++) {
      if(diceNumCheck(dice1, dice3)) return "Yes"; //サイコロが一致したらYes
      if(j == 4) break;
      diceSpin(dice3);
    }
  }
  return "No";
}

int main() {
  int n, num;
  scanf("%d", &n);
  vector<Dice> dice(n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 6; j++) {
      scanf("%d", &num);
      dice.at(i).num.push_back(num);
    }
  }
  
  string same;
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      same = diceAllCheck(dice.at(i), dice.at(j)); //全探索
      if(same == "Yes") break; //同一のものを発見した場合終了
    }
    if(same == "Yes") break;
  }
  
  string ans = (same == "Yes") ? "No" : "Yes";
  printf("%s\n", ans.c_str());
}