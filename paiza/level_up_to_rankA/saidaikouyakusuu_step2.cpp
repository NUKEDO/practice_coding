// 参考
// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an

#include <bits/stdc++.h>
using namespace std;
#define PN 1000003 // PrimeNumber

int main() {
  long long n; // ex) n=45の時 45(10進数表示)=101101(2進数表示)
  scanf("%lld\n", &n); // 2^45 = 2^32 * 2^8 * 2^4 * 2^0
  long long rev = 2, ans = 1; // rev:2のx乗を作成する
  while(n > 0) { // 各(%PN)がなければ2のn乗を計算するだけになる
    if(n & 1) ans = ans * rev % PN; // (n & 1) : 2進数表記されたnの1桁目のビットが1
    rev = rev * rev % PN; // 2のx乗を更新
    n >>= 1; // 101101 を右に１ずらし 10110にする
  }
  printf("%lld\n", ans);
}