#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int sum = 0;
  int surplus_1 = 0, surplus_2 = 0;
  for(int i = 0; i < str.size(); i++) {
    sum += str.at(i) - '0';
    if((str.at(i) - '0') % 3 == 1) surplus_1++;
    else if((str.at(i) - '0') % 3 == 2) surplus_2++;
  }
  
  int ans = -1;
  if(sum % 3 == 0) {
    ans = 0;
  } else if(sum % 3 == 1) {
    if(str.size() >= 2 && surplus_1 >= 1) ans = 1;
    else if(str.size() >= 3 && surplus_2 >= 2) ans = 2;
  } else if(sum % 3 == 2) {
    if(str.size() >= 2 && surplus_2 >= 1) ans = 1;
    else if(str.size() >= 3 && surplus_1 >= 2) ans = 2;
  }
  
  printf("%d\n", ans);
}