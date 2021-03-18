// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D&lang=ja
// 螺旋本を見ながら作成

#include <bits/stdc++.h>
using namespace std;

int n, k;

int check(vector<int> w, long long mid) {
  int i = 0;
  long long sum;
  for(int j = 0; j < k; j++) {
    sum = 0;
    while(sum + w.at(i) <= mid) { //次の荷物を載せても最大積載量を超えないなら次も載せる
      sum += w.at(i);
      i++;
      if(i == n) return n; //全荷物を載せられた
    }
  }
  return i; //i個目の荷物まで載せられた
}

int solve(vector<int> w) {
  long long mid, left = 0, right = n * 10000; // 荷物個数 * 最大重量
  while(right - left > 1) { // (right == left)の時はもう決定しているので一つ手前で終了する
    mid = (right + left) / 2;
    // チェック用 cout << "right:left:mid = " << right << ":" << left << ":" << mid << endl;
    (check(w, mid) >= n) ? (right = mid) : (left = mid);
    // 全荷物を載せられたなら最大積載量はもっと少なくできる　載せられないならもっと大きくする
  }
  return right;
}

int main() {
  int ans;
  scanf("%d %d\n", &n, &k);
  vector<int> w(n);
  for(int i = 0; i< n; i++) {
    scanf("%d\n", &w.at(i));
  }
  ans = solve(w);
  printf("%d\n", ans);
}