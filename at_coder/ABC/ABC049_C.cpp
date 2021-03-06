#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S, str, ans;
  cin >> S;
  vector<string> word = {"dream", "dreamer", "erase", "eraser"};
  reverse(S.begin(), S.end());
  for(int i = 0; i < 4; i++) {
    reverse(word.at(i).begin(), word.at(i).end());
  }
  
  for (int i = 0; i < S.size(); ) {
    ans = "NO";
    for (int j = 0; j < 4; j++) {
      str = word.at(j);
      if (S.substr(i, str.size()) == str) { // substr (引数1)から(引数２)文字分の文字を抜き出す
        ans = "YES";
        i += str.size();
        }
      }
    if (ans == "NO") {
      break;
    }
  }
  printf("%s\n", ans.c_str());
}