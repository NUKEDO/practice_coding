#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  string str, com, rev, rep;
  cin >> str >> n;
  for(int i = 0; i < n; i++) {
    cin >> com >> a >> b;
    
    if(com == "replace") cin >> rep;
    else if(com == "reverse") rev = str;
    
    for(int j = a; j <= b; j++) {
      if(com == "print") {
        printf("%c", str.at(j));
        if(j == b) printf("\n");
        
      } else if(com == "reverse") {
        str.at(j) = rev.at(a + b - j);
        
      } else if(com == "replace") {
        str.at(j) = rep.at(j - a);
      }
    }
  }
}