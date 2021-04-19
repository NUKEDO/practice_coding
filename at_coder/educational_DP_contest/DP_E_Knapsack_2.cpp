// https://atcoder.jp/contests/dp/tasks/dp_e
// 参考 http://9871225.blog.fc2.com/blog-entry-300.html

#include <bits/stdc++.h>
using namespace std;
#define LL_MAX 100000000001 // 10の11乗 + 1
 
int main() {
  int N, W, ans = 0, sum_v = 0;
  cin >> N >> W;
  long long w, v; // w:weight, v:value
  vector<vector<long long> > A(N + 1, vector<long long>(100000 + 1, LL_MAX) );
  for(int i = 1; i <= N; i++) {
    cin >> w >> v;
    sum_v += v;
    for(int j = 1; j <= sum_v; j++) {
      if(A.at(i - 1).at(j) != LL_MAX) A.at(i).at(j) = min(A.at(i - 1).at(j), A.at(i).at(j));
      if(j == v) A.at(i).at(j) = min(A.at(i - 1).at(j), w);
      
      if(j - v >= 1 && A.at(i - 1).at(j - v) != LL_MAX) {
        A.at(i).at(j) = min(A.at(i - 1).at(j), A.at(i - 1).at(j - v) + w);
      }
      
      //テスト出力用
      // if(i == 5 && j == 9) cout << A.at(i).at(j + v) << endl;
      
      if(i == N && A.at(i).at(j) <= W) {
        ans = j;
        // cout << j; //テスト出力用
      }
      
      /* //テスト出力用
      int x = 20;
      if(j <= x) {
      */
      /*
      if(j % 1000 == 0) {
        if(A.at(i).at(j) == LL_MAX) cout << "-- ";
        else if(A.at(i).at(j) < 10) cout << " " << A.at(i).at(j) << " ";
        else cout << A.at(i).at(j) << " ";
      }
      */
      //if(j == x) cout << endl;
    }
  }
  cout << ans << endl;
}