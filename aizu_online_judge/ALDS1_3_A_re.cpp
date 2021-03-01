// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=ja
// 螺旋本を見て解き方が間違ってたので作り直し

// stack風の配列を作成し、それを利用して開放にする
#include <bits/stdc++.h>
using namespace std;

void pop(vector<int> num) {
  int n = num.back();
  num.pop_back();
  return n;
}

void push(vector<int> num, int str) {
  num.push_back(str);
}

int main() {
  int a, b, culc;
  vector<int> num;
  string str;
  while (cin >> str) {
    if (str.at(0) == '+' || str.at(0) == '-' || str.at(0) == '*') {
      a = pop(num); //後方の数
      b = pop(num);
      if (str.at(0) == '+') {
        culc = a + b;
      } else if (str.at(0) == '-') {
        culc = b - a;
      } else if (str.at(0) == '*') {
        culc = a * b;
      }
    } else {
      culc = stoi(str);
    }
    push(num, culc);
  }
  cout << pop(num) << endl;
}