#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(8);
  double x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  double dis_x = x2 - x1, dis_y = y2 - y1;
  double sum = pow(dis_x, 2) + pow(dis_y, 2);
  sum = pow(sum, 1.0 / 2.0);
  printf("%lf\n", sum);
}