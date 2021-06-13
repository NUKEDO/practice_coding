#include <bits/stdc++.h>
using namespace std;

void printVec(vector<long long> v) {
  for(int i = 0; i < v.size(); i++) {
    if(i) printf(" ");
    printf("%lld", v.at(i));
  }
  printf("\n");
}

int main() {
  long long n;
  scanf("%lld\n", &n);
  vector<long long> num(n), max_dis(n);
  scanf("%lld", &num.at(0));
  max_dis.at(0) = (num.at(0) > 0) ? num.at(0) : 0;
  long long x;
  for(int i = 1; i < n; i++) {
    scanf("%lld", &x);
    num.at(i) = num.at(i - 1) + x; //合計進行位置
    max_dis.at(i) = max(max_dis.at(i - 1), num.at(i)); //瞬間最大位置
  }
  //printVec(num);
  //printVec(max_dis);
  
  long long sum = num.at(0), ans = max_dis.at(0);
  //printf("%lld ", sum);
  for(int i = 1; i < n; i++) {
    ans = max(ans, sum + max_dis.at(i));
    sum += num.at(i); //最終到達位置
    //printf("%lld ", sum);
  }
  
  printf("%lld\n", ans);
}