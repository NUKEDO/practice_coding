#include <bits/stdc++.h>
using namespace std;
int is_prime(int N, int D) {
  /*
  N = 7の時
  2~6で割れるかを確認
  = 6で割れるかを確認 + 2~5で割れるかを確認
  = 6,5で割れるかを確認 + 2~4で割れるかを確認
  */
  
  if (D == 1 || N == 2) {
    return 1; //素数であれば1を返す
  }
  else if (N == 1 || N % D == 0 || N % 2 == 0) { // N=1の時 N%D が0除算になるので先に書く
    return 0; //素数でなければ0を返す
  }
  
  return is_prime(N, D - 1);
}

int main() {
  int N;
  cin >> N;
  cout << is_prime(N, N - 1) << endl;
}