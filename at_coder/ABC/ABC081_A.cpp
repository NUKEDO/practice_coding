#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int sum = 0, num;
  for(int i = 0; i < str.size(); i++) {
    num = str.at(i) - '0';
    sum += num;
  }
  printf("%d\n", sum);
}