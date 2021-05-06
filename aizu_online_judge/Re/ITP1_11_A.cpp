#include <bits/stdc++.h>
using namespace std;

struct Dice {
  vector<int> num;
};

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

int main() {
  Dice dice;
  int n;
  for(int i = 0; i < 6; i++) {
    scanf("%d", &n);
    dice.num.push_back(n);
  }
  
  char c;
  while(cin >> c) {
    diceRoll(dice, c);
  }

  printf("%d\n", dice.num.at(0));
}