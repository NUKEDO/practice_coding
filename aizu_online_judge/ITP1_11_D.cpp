// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

struct Dice {
  vector<int> number;
  int save;
  
  void set(vector<int> num) {
    if (number.size() > 0) {
      for(int i = 0; i < 6; i++) {
        number.pop_back();
      }
    }
    for (int i = 0; i < 6; i++) {
      number.push_back(num.at(i));
    }
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
  int n;
  cin >> n;
  vector<vector<int>> all_num(n, vector<int>(6));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> all_num.at(i).at(j);
    }
  }
  
  Dice dice, another_dice;
  vector<int> num(6), another_num(6);
  int x, y, z;
  string ans;
  vector<string> turn = {"", "N", "NW", "NE", "S", "NN"};

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < 6; k++) {
        num.at(k) = all_num.at(i).at(k);
        another_num.at(k) = all_num.at(j).at(k);
      }
      
      dice.set(num);
      another_dice.set(another_num);
      
      ans = "No";      
      if( another_dice.same_number(dice) ) {
        for (int k = 0; k < 6; k++) {
          if (k != 0){
            another_dice.roll(turn.at(k));
          }

          ans = another_dice.same_check(dice);
          if( ans == "Yes" ){
            break;
          }
      
          x = dice.key(1);
          y = another_dice.key(1);
      
          z = 0;
          while (z < 3) {
            another_dice.spin();
        
            ans = another_dice.same_check(dice);
            if(ans == "Yes") {
              break;
            }
        
            z++;
          }
          if(ans == "Yes") {
            break;
          }
      
          another_dice.set(another_num);
      
        }
        if(ans == "Yes") {
            break;
        }
      }
      if(ans == "Yes") {
            break;
      }
    }
    if (ans == "Yes") {
      break;
    }
  }
  
  string diffe_ans;
  if (ans == "Yes") {
    diffe_ans = "No";
  } else {
    diffe_ans ="Yes";
  }
  cout << diffe_ans << endl;
}