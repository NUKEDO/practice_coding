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

int main() {
  Dice dice;
  int num;
  for(int i = 0; i < 6; i++) {
    scanf("%d", &num);
    dice.num.push_back(num);
  }
  
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num);
    setDiceTop(dice, num); //上面を合わせる
    scanf("%d", &num);
    for(int j = 0; j < 3; j++) { //前面を合わせる
      if(dice.num.at(1) == num) break;
      diceSpin(dice);
    }
    printf("%d\n", dice.num.at(2)); //右側面を出力
  }
  

}