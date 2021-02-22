#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string str, ans = "Yes";
  cin >> str;
  
  for( int i = 0; i < str.size(); i++) {
    if(i % 2 == 0) { //１文字目　小文字の時
      if(str.at(i) >= 'A' && str.at(i) <= 'Z') {
        ans = "No";
      }
    } else {
      if(str.at(i) >= 'a' && str.at(i) <= 'z') {
        ans = "No";
      }
    }
    if (ans == "No") {
        break;
    }
  }
  cout << ans << endl;
}