#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  vector<int> abc(26, 0);
  while(getline(cin, str)) {
    int n = str.size();
    for(int i = 0; i < n; i++) {
      char c = str.at(i);
      if(c >= 'A' && c <= 'Z') c -= 'A' - 'a'; //大文字を小文字化
      
      int p = c - 'a'; //c == 'a' の時 p = 0;
      if(p >= 0 && p < 26) abc.at(p)++;
    }
  }
  
  char alp = 'a';
  for(int i = 0; i < 26; i++) {
    printf("%c : %d\n", alp, abc.at(i));
    alp++;
  }
}