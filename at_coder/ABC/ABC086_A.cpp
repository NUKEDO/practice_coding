#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  string ans = (a % 2 == 0 || b % 2 == 0) ? "Even" : "Odd";
  printf("%s\n", ans.c_str());
}

