// stoi()が使えるc++11にて提出

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  stack<int> s;
  while (cin >> str) {
    if(str == "+" || str == "-" || str == "*") {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      if(str == "+") a += b;
      else if(str == "-") a -= b;
      else if(str == "*") a *= b;
      s.push(a);
    } else {
      int num = stoi(str);
      s.push(num);
    }
  }
  cout << s.top() << endl;
}