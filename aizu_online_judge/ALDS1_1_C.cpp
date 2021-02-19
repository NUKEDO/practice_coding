// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int num) {
  if (num <= 1) {
    return false;
  } else if(num <= 3) {
    return true;
  }
  
  double new_num = pow(num, 1.0 / 2.0);
  for (int i = 2; i <= new_num; i++) {
    if(num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, num, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (is_prime(num)) { 
      sum += 1;
    }
  }
  cout << sum << endl;
}