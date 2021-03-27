// https://atcoder.jp/contests/abc187/tasks/abc187_c

#include <bits/stdc++.h>
using namespace std;

string ans = "satisfiable";

void searchSame(set<string> A, set<string> B) {
  for(auto word : A) {
    if(B.count(word)) {
      string save;
      for(int i = 1; i < word.size(); i++) {
        save.push_back(word.at(i));
      }
      ans = save;
      break;
    }
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  string s;
  set<string> A, B;
  for(int i = 0; i < n; i++) {
    cin >> s;
    if(s.at(0) != '!') {
      s = "!" + s;
      A.insert(s);
    } else {
      B.insert(s);
    }
  }
  
  searchSame(A, B);
  printf("%s\n", ans.c_str());
}