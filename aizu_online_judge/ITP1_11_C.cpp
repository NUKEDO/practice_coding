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
  
  int key(int i) {
    return number.at(i);
  }
  
  void spin() {
    save = number.at(1);
    number.at(1) = number.at(3);
    number.at(3) = number.at(4);
    number.at(4) = number.at(2);
    number.at(2) = save;
  }


  bool check(int num, int i) {
    if (num == number.at(i)) {
      return true;
    } else {
      return false;
    }
  }
  
  bool same_number(Dice dice) {
    int sum = 0;
    vector<int> used(6, 1);
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        if(number.at(i) == dice.key(j)) {
          if(used.at(j) == 1) {
            used.at(j) = 0;  
            sum++;
          } else {
            continue;
          }
        }
      }
    }
    if (sum == 6) {
      return true;
    } else {
      return false;
    }
  }
  
  string same_check(Dice dice) {
    string str = "Yes";
    for (int i = 0; i < 6; i++) {
      if(number.at(i) != dice.key(i) ) {
        str = "No";
      }
    }
    return str;
  }
  
};


int main() {
  string direction;
  vector<int> num(6);
  for (int i = 0; i < 6; i++) {
    cin >> num.at(i);
  }
  
  Dice dice;
  dice.set(num);
  
  vector<int> default_num(6);
  for (int i = 0; i < 6; i++) {
    cin >> default_num.at(i);
  }
  
  Dice another_dice;
  another_dice.set(default_num);
  
  int x, y, z;
  string ans;
  vector<string> turn = {"", "N", "NW", "NE", "S", "NN"};
  if( another_dice.same_number(dice) ) {
    for (int i = 0; i < 6; i++) {
      //一番上を変える
      if (i != 0){
        another_dice.roll(turn.at(i));
      }
      
      x = dice.key(1);
      y = another_dice.key(1);
      
      ans = another_dice.same_check(dice);
      if( ans == "Yes" ){
        break;
      }
      
      //正面比較
      z = 0;
      while (z < 3) {
        another_dice.spin();
        
        ans = another_dice.same_check(dice);
        if( ans == "Yes" ){
          break;
        }
        
        z++;
      }
      if( ans == "Yes" ){
        break;
      }
      
      for(int j = 0; j < 6; j++) {
        another_dice.number.at(j) = default_num.at(j);
      }
      
    }
  }
  cout << ans << endl;
}