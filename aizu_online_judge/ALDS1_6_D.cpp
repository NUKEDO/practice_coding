// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_D&lang=ja
// 螺旋本の通りに作成

#include <bits/stdc++.h>
using namespace std;

int n, cost = 0;

void costSort(vector<int> A, int s) {
  vector<int> T(10001); 
  vector<bool> V(n, false);
  vector<int> B(n);
  for(int i = 0; i < n; i++) {
    B.at(i) = A.at(i);
  }
  sort(B.begin(), B.end()); // A={1,7,5,4,2}, B={1,2,4,5,7}
  for(int i = 0; i < n; i++) {
    T.at(B.at(i)) = i; // T={-,0,1,-,2,3,-,4}
  }
  
  int cur, S, m, an, v;
  for(int i = 0; i < n; i++) {
    if(V.at(i)) continue; //V.at(i) == trueならすでにサークル作成済み
    cur = i;
    S = 0;
    m = INT_MAX;
    an = 0;
    while(1) { // サークル作成
      V.at(cur) = true; // 開始位置をtrueに変更
      an++; // 交換回数
      v = A.at(cur); // A.at(i)
      m = min(m, v); // サークル内の最小値を記録
      S += v;
      cur = T.at(v); // cur = T.at(A.at(i))
      if(V.at(cur)) break; // すでにtrueなら１周してるので終了
    } // 「サークル内のみの交換」と「サークル外から最小値を持ってきた場合の交換」のより小さい方を選択
    cost += min(S + (an - 2) * m, m + S + (an + 1) * s);
  }
}

int main() {
  int s = INT_MAX;
  scanf("%d\n", &n);
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &A.at(i));
    s = min(s, A.at(i));
  }

  costSort(A, s);

  printf("%d\n", cost);
}