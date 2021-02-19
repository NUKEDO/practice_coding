// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> num, int n) {
  vector<int> comp(n, -1);
  int x, y;
  for (int i = 0; i < n; i++) {
    x = num.at(i);
    comp.at(i) = x;
    y = i;
    while (y >= 1 && x < comp.at(y - 1)) {
      comp.at(y) = comp.at(y - 1);
      comp.at(y - 1) = x;
      y--;
    }

    for (int j = 0; j < n; j++) {
      if (comp.at(j) == -1) {
        cout << num.at(j);
      } else {
        cout << comp.at(j);
      }
      if (j != n - 1) {
        cout << " ";
      } else {
        cout << endl;
      }
    }  
  } 
}
  
int main() {
  int n;
  cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n; i++) {
    cin >> num.at(i);
  }
  
  insertionSort(num, n);
}