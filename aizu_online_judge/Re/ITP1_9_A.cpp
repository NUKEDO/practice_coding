#include <bits/stdc++.h>
using namespace std;

string s, p;

int checkSame() {
  int s_size = s.size(), p_size = p.size();
  if(s_size != p_size) return 0;
  for(int i = 0; i < s_size; i++) {
    if(s.at(i) != p.at(i)) return 0;
  }
  return 1;
}

void changeSmall(string &str) { // 大文字があれば小文字に変える
  int str_size = str.size();
  for(int i = 0; i < str_size; i++) {
    if(str.at(i) >= 'A' && str.at(i) <= 'Z') str.at(i) -= 'A' - 'a';
  }
}

int main() {
  cin >> p;
  changeSmall(p);
  int cnt = 0;
  while(cin >> s) {
    if(s == "END_OF_TEXT") break;
    changeSmall(s);
    cnt += checkSame();
  }
  
  printf("%d\n", cnt);
}