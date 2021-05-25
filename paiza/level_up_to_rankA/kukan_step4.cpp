#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int n, m, min_cnt = INT_MAX, max_cnt = 0;
vector<int> num(MAX), dp(MAX), cnt(MAX);

void makeMinCnt() {
  int j = 0;
  for(int i = 0; i < n; i++) {
    if(i == 0) {
      dp.at(i) = num.at(i);
      cnt.at(i) = 1;
    } else {
      dp.at(i) = dp.at(i - 1) + num.at(i);
      cnt.at(i) = cnt.at(i - 1) + 1;
      while(j < i && dp.at(i) >= m) {
        if(dp.at(i) - num.at(j) >= m) {
          dp.at(i) -= num.at(j);
          cnt.at(i)--;
          j++;
        } else break;
      }
    }
    if(dp.at(i) >= m) min_cnt = min(min_cnt, cnt.at(i));
  }
  if(min_cnt == INT_MAX) min_cnt = -1;
}

void makeMaxCnt() {
  int j = 0;
  for(int i = 0; i < n; i++) {
    if(i == 0) {
      dp.at(i) = num.at(i);
      cnt.at(i) = 1;
    } else {
      dp.at(i) = dp.at(i - 1) + num.at(i);
      cnt.at(i) = cnt.at(i - 1) + 1;
      while(j < i && dp.at(i) >= m) {
        dp.at(i) -= num.at(j);
        cnt.at(i)--;
        j++;
      }
    }
    if(dp.at(i) < m) max_cnt = max(max_cnt, cnt.at(i));
  }
}

void printVec(vector<int> v) {
  for(int i = 0; i < n; i++) {
    if(i) printf(" ");
    printf("%d", v.at(i));
  }
  printf("\n");
}

int main() {
  scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num.at(i));
  }
  
  //makeMinCnt();
  makeMaxCnt();
  
  //printVec(dp);
  //printVec(cnt);
  
  //printf("%d\n", min_cnt);
  printf("%d\n", max_cnt);
}