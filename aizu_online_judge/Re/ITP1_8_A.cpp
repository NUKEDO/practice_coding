#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  while(getline(cin, str)) {
    int n = str.size();
    for(int i = 0; i < n; i++) {
      char c = str.at(i);
      
      if(c >= 'a' && c <= 'z') c += 'A' - 'a';
      else if(c >= 'A' && c <= 'Z') c -= 'A' - 'a';
      
      printf("%c", c);
    }
    printf("\n");
  }
}