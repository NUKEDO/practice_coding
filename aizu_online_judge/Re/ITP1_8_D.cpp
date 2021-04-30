#include <bits/stdc++.h>
using namespace std;

string s, p;

int checkSame() {
  int s_size = s.size(), p_size = p.size();
  for(int i = 0; i < s_size; i++) {
    if(s.at(i) == p.at(0)) { // 1文字目が一致した時
      for(int j = 0; j < p_size; j++) {
        int k = (i + j >= s_size) ? (i + j - s_size) : (i + j);
        if(s.at(k) != p.at(j)) break;

        if(j == p_size - 1) return 1; //全部一致
      }
    }
  }
  return 0; //全部不一致
}

int main() {
  cin >> s >> p;
  
  string ans = (checkSame()) ? "Yes" : "No";
  printf("%s\n", ans.c_str());
}