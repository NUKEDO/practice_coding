#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  while(scanf("%d %d", &n, &x)) {
    if(n == 0 && x == 0) break;

    int cnt = 0;
    // int sum = 0; // 計算回数 1/3
    for(int i = n; i >= 3; i--) { //最大値 i > j > k
      for(int j = i - 1; j >= 2; j--) { //中間値
        // sum++; // 計算回数 2/3
        if(j >= i) continue;
        
        int k = x - i - j; //最小値
        if(k <= 0) continue;
        if(k >= j) break;
        cnt++;
        
        // printf("i:j:k=%d:%d:%d\n", i, j, k); //テスト出力用
      }
    }

    printf("%d\n", cnt);
    // printf("%d\n", sum); //計算回数 3/3
  }
}