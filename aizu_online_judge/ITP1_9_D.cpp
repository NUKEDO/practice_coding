// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

void print(int a, int b, string str) {
  for (int i = a; i <= b; i++) {
    cout << str.at(i);
  }
  cout << endl;
}

string reverse(int a, int b, string str) {
  string new_word = "";
  for (int i = 0; i < str.size(); i++) {
    if (i < a || i > b) {
      new_word.push_back(str.at(i));
    } else {
      new_word.push_back(str.at(b - (i - a)));
    }
  }
  return new_word;
}

string replace(int a, int b, string p, string str) {
  string new_word = "";
  for (int i = 0; i < str.size(); i++) {
    if (i < a || i > b) {
      new_word.push_back(str.at(i));
    } else {
      new_word.push_back(p.at(i - a));
    }
  }
  return new_word;
}

int main() {
  int n, a, b;
  string str, command, p;
  cin >> str >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> command >> a >> b;
    if (command == "print") {
      print(a, b, str);
    } else if (command == "reverse") {
      str = reverse(a, b, str);
    } else if (command == "replace") {
      cin >> p;
      str = replace(a, b, p, str);
    }
  }
}
