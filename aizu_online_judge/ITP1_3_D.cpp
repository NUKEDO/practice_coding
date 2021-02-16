// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, i = 0;
  cin >> a >> b >> c;

  do {
    if (c % a == 0) {
      i++;
    }
    if (a >= b){
      break;
    }
    a++;
  } while(a <= b);
  
  cout << i << endl;
}