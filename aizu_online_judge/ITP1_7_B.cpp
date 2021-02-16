// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, sum = 0, num = 0;  
  cin >> n >> x;
  
  while(n != 0 || x != 0) {
    for (int i = 1; i <= n - 2; i++) {
      for (int j = i + 1; j <= n - 1; j++) {
        for (int k = j + 1; k <= n; k++) {
          sum = i + j + k;
          if(sum == x) {
            num += 1;
          }
        }
      }
    }
    cout << num << endl;
    
    num = 0;
    cin >> n >> x;
  }
}
