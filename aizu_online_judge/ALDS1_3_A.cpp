// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  vector<string> formula;
  while (cin >> str) {
    formula.push_back(str);
  }
  
  int N = formula.size(), count ,result;
  vector<int> num;
  for (int i = 0; i < N; i++) {
    if (formula.at(i).at(0) >= '0' && formula.at(i).at(0) <= '9') {
      num.push_back(stoi (formula.at(i)) );
    } else {
      count = num.size() - 2;
      if (formula.at(i) == "+") {
        result = num.at(count) + num.at(count + 1); 
      } else if (formula.at(i) == "-") {
        result = num.at(count) - num.at(count + 1); 
      } else if (formula.at(i) == "*") {
        result = num.at(count) * num.at(count + 1); 
      }
      num.pop_back();
      num.pop_back();
      num.push_back(result);
    }
  }
  
  cout << num.at(0) << endl;
}