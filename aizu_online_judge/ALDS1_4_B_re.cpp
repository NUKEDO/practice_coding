// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja
// 螺旋本とvec_endの取り方が異なっていたのでやり直し（自分:n-1 本:n)

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> vec, int key) {
  int left = 0, right = vec.size(), mid;
  while(left < right){
    mid = (left + right) / 2;
    if(vec.at(mid) == key) return 1;
    if(vec.at(mid) > key) right = mid;
    else if(vec.at(mid) < key) left = mid + 1;
  }
  return 0;
}


int main() {
  int n, q, T;
  scanf("%d\n", &n);
  vector<int> S(n);
  for(int i = 0; i < n; i++){
    scanf("%d", &S.at(i));
  }
  
  scanf("%d\n", &q);
  int sum = 0;
  for(int i = 0; i < q; i++){
    scanf("%d", &T);
    sum += binarySearch(S, T);
  }

  printf("%d\n", sum);
}