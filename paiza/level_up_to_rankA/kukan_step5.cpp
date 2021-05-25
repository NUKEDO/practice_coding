#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int n, m, l, u, a;
vector<int> num(MAX), add(MAX + 1, 0); //いもす法

void printVec(vector<int> v) {
  for(int i = 0; i < n; i++) {
    printf("%d\n", v.at(i));
  }
}

int main() {
  scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num.at(i));
  }
  
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", &l, &u, &a);
    l--;
    u--;
    add.at(l) += a;
    add.at(u + 1) -= a;
  }
  
  for(int i = 0; i < n; i++) {
    num.at(i) += add.at(i);
    add.at(i + 1) += add.at(i);
  }
  
  printVec(num);
}