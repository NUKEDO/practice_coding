// https://atcoder.jp/contests/abc188/tasks/abc188_c

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, nop, rate, left = INT_MIN, right = INT_MIN, saveL, saveR; // nop:number of people
  scanf("%d\n", &n);
  nop = 1 << n;
  for(int i = 0; i < nop; i++) {
    scanf("%d\n", &rate);
    if(i < nop / 2) { //左の勝ち上がり
      if(rate > left) {
        left = rate;
        saveL = i;
      }
    } else { //右の勝ち上がり
      if(rate > right) {
        right = rate;
        saveR = i;
      }
    }
  }
  int ans = (left > right) ? saveR : saveL; //負けた方のiを出力
  ans++; // iは0からなので1からにする
  
  printf("%d\n", ans);
}