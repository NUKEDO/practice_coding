#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, num;
  scanf("%d %d", &h, &w);
  int sum_w, sum_full = 0;
  vector<int> sum_h(w, 0);
  for(int i = 0; i < h; i++) {
    sum_w = 0;
    for(int j = 0; j < w; j++) {
      scanf("%d", &num);
      
      sum_w += num; //横計算
      sum_full += num; //総合計
      sum_h.at(j) += num; //縦計算
      
      printf("%d ", num);
      if(j == w - 1) printf("%d\n", sum_w);
    }
  }
  for(int i = 0; i < w; i++) {
    printf("%d ", sum_h.at(i));
  }
  printf("%d\n", sum_full);

}