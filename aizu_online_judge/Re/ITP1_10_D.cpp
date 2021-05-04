#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(8);
  int n;
  scanf("%d", &n);
  vector<int> x(n), y(n);
  vector<double> z(n);
  double sum_z = 0, max_z = INT_MIN;
  for(int i = 0; i < n; i++) scanf("%d", &x.at(i));
  for(int i = 0; i < n; i++) {
    scanf("%d", &y.at(i));
    z.at(i) = abs(x.at(i) - y.at(i));
    sum_z += z.at(i);
    if(z.at(i) > max_z) max_z = z.at(i);
  }
  
  double sum_z2 = 0, sum_z3 = 0;
  for(int i = 0; i < n; i++) {
    sum_z2 += pow(z.at(i), 2);
    sum_z3 += pow(z.at(i), 3);
  }
  sum_z2 = pow(sum_z2, 1.0 / 2.0);
  sum_z3 = pow(sum_z3, 1.0 / 3.0);
  
  printf("%lf\n%lf\n%lf\n%lf\n", sum_z, sum_z2, sum_z3, max_z);
}