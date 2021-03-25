// https://atcoder.jp/contests/abc189/tasks/abc189_c

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector<int> A(N), B(N); // A={2,4,4,9,4,9}
  for(int i = 0; i < N; i++) {
    scanf("%d", &A.at(i));
    B.at(i) = A.at(i);
  }
  sort(B.begin(), B.end());
  int m = INT_MIN;
  vector<int> C; // C={2,4,9} 
  for(int i = 0; i < N; i++) {
    if(B.at(i) > m) {
      C.push_back(B.at(i));
      m = B.at(i);
    }
  }
  
  int size_C = C.size(), k, sum, save = INT_MIN;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < size_C; j++) {
      if(A.at(i) >= C.at(j)) {
        k = i;
        sum = 0;
        while(k < N && A.at(k) >= C.at(j)){
          sum += C.at(j);
          k++;
        }
      }
      save = max(sum, save);
    }
  } 
  printf("%d\n", save);
}