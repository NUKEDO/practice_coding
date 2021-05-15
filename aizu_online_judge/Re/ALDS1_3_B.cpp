#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  scanf("%d %d\n", &n, &t);
  queue<string> name;
  queue<int> time;
  string str;
  int num;
  for(int i = 0; i < n; i++) {
    cin >> str >> num;
    name.push(str);
    time.push(num);
  }
  
  int cur = 0; // cur:current
  while(!name.empty()) {
    num = time.front();
    time.pop();
    str = name.front();
    name.pop();
    if(num <= t) {
      cur += num;
      printf("%s %d\n", str.c_str(), cur);
    } else {
      cur += t;
      num -= t;
      name.push(str);
      time.push(num);
    }
  }
}