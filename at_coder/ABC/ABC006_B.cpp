#include <bits/stdc++.h>
using namespace std;

int makeTri(int n) {
  if(n == 1 || n == 2) return 0;
  else if(n == 3) return 1;
  else {
    vector<int> v(n);
    v.at(0) = 0;
    v.at(1) = 0;
    v.at(2) = 1;
    int j = 3;
    while(j < n) {
      v.at(j) = (v.at(j - 1) + v.at(j - 2) + v.at(j - 3)) % 10007;
      j++;
    }
    return v.at(n - 1);
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  int ans = makeTri(n);
  cout << ans << endl;
}