// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja
// 螺旋本を参考に作成
// 二重配列なのでC++14で提出

#include <bits/stdc++.h>
using namespace std;

void LCS(string A, string B) {
  int A_size = A.size(), B_size = B.size();
  vector<vector<int>> c(A_size + 1, vector<int>(B_size + 1, 0));
  A = ' ' + A;
  B = ' ' + B;
  for(int i = 1; i <= A_size; i++) {
    for(int j = 1; j <= B_size; j++) {
      c.at(i).at(j) = (A.at(i) == B.at(j))
        ? c.at(i - 1).at(j - 1) + 1 // それまでに一致した文字列+1
        : max(c.at(i - 1).at(j), c.at(i).at(j - 1)); // それまでに一致した最大数
      // printf("i:j:c = %d:%d:%d\n", i, j, c.at(i).at(j)); // 確認用
    }
  }
  printf("%d\n", c.at(A_size).at(B_size));
}

int main() {
  int n;
  scanf("%d\n", &n);
  string A, B;
  for(int i = 0; i < n; i++) {
    cin >> A >> B;
    LCS(A, B);
  }
}