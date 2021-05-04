#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, num, sum;
  string str;
  
  while(cin >> str) {
    if(str == "-") break;
    sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &num);
      sum += num;
    }
  
    sum %= str.size();
    int sum_str = sum + str.size();
    for(int i = sum; i < sum_str; i++) {
      if(i >= str.size()) printf("%c", str.at(i - str.size()));
      else printf("%c", str.at(i));
    }
    printf("\n");
  }
}