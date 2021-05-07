#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> A(n), minA(n);
  int save_min = INT_MAX;
  for(int i = 0; i < n; i++) {
    scanf("%d", &A.at(i));
    if(save_min > A.at(i)) save_min = A.at(i);
    minA.at(i) = save_min; //時点iを含めての最小値
  }
  
  int profit = INT_MIN;
  for(int i = 1; i < n; i++) {
    if(profit < A.at(i) - minA.at(i - 1)) profit = A.at(i) - minA.at(i - 1);
  }
  
  printf("%d\n", profit);
}