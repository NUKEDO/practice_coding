// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

int main() { //計算量 O(NW)
  int N, W;
  scanf("%d %d\n", &N, &W);
  long long w, v; // w:weight, v:value
  vector<vector<long long> > A( N + 1, vector<long long>(W + 1, 0) );
  for(int i = 1; i <= N; i++) {
    scanf("%lld %lld\n", &w, &v);
    for(int j = 1; j <= W; j++) {
      if(j < w) A.at(i).at(j) = A.at(i - 1).at(j);
      else A.at(i).at(j) = max(A.at(i - 1).at(j), A.at(i - 1).at(j - w) + v);
      // printf("%lld ", A.at(i).at(j)); //テスト出力用
    }
    // printf("\n"); //テスト出力用
  }
  printf("%lld\n", A.at(N).at(W));
}