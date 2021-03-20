// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=ja
// 螺旋本の通りに作成

#include <bits/stdc++.h>
using namespace std;

struct Point{
  double x;
  double y;
};

void koch(int n, Point a, Point b) {
  if(n == 0) return;
  Point s, t, u;
  double th = M_PI * 60 / 180; // doubleなのに「.0」必要？
  s.x = (2 * a.x + 1 * b.x) / 3;
  s.y = (2 * a.y + 1 * b.y) / 3;
  t.x = (1 * a.x + 2 * b.x) / 3;
  t.y = (1 * a.y + 2 * b.y) / 3;
  // 回転行列による点u作成
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
  
  koch(n - 1, a, s);
  printf("%.8f %.8f\n", s.x, s.y);
  koch(n - 1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);
  koch(n - 1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  koch(n - 1, t, b);
}

int main() {
  int n;
  scanf("%d\n", &n);
  Point a, b;
  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;
  
  printf("%.8f %.8f\n", a.x, a.y);
  koch(n, a, b);
  printf("%.8f %.8f\n", b.x, b.y);
}