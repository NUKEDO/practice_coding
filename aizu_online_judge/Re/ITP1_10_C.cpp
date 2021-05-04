#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(8);
  int n;
  while(scanf("%d", &n)) {
    if(n == 0) break;
    
    vector<int> num(n);
    double ave = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &num.at(i));
      ave += num.at(i);
    }
    ave /= n;
    
    double sum = 0;
    for(int i = 0; i < n; i++) {
      sum += pow(num.at(i) - ave, 2);
    }
    sum /= n;
    sum = sqrt(sum);
    
    printf("%lf\n", sum);
  }
}