#include <bits/stdc++.h>
using namespace std;

void call(int n){
  for(int i = 1; i <= n; i++) {
    int x = i;
    if ( x % 3 == 0 ){
      cout << " " << i;
    } else {
      while(x) {
        if ( x % 10 == 3 ){
          cout << " " << i;
          break;
        }
        x /= 10;
      }
    }
  }
  cout << endl;
}

int main() {
  int n;
  scanf("%d", &n);
  call(n);
}