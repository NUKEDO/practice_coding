#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(8);
  double w, s, c, S, L, h;
  scanf("%lf %lf %lf", &w, &s, &c);
  h = s * sin(2 * M_PI * c / 360);
  S = w * h / 2;
  L = pow(w * w + s * s - 2 * w * s * cos(2 * M_PI * c / 360), 1.0 / 2.0);
  // c^2 = a^2 + b^2 - 2ab*cos(角度)
  L += w + s;
  printf("%lf\n%lf\n%lf\n", S, L, h);
}