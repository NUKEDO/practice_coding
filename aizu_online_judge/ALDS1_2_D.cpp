// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int>A, int n, int g, int &cnt) {
  int v, j;
  for (int i = g; i < n; i++) {
    v = A.at(i);
    j = i - g;
    while (j >= 0 && A.at(j) > v) {
      A.at(j + g) = A.at(j);
      j = j - g;
      cnt++;
    }
    A.at(j + g) = v;
  }
  return A;
}

void shellSort(vector<int> num, int N) {
  int n = 1;
  vector<int> G;
  G.push_back(n);
  n = 3 * n + 1;
  
  while (N > n) {
    G.push_back(n);
    n = 3 * n + 1;
  }
  reverse(G.begin(), G.end() );
  int m = G.size();

  cout << m << endl;
  for (int i = 0; i < m; i++) {
    cout << G.at(i);
    if(i != m - 1) {
      cout << " ";
    }
  }
  cout << endl;
  
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    num = insertionSort(num, N, G.at(i), cnt);
  }
  
  cout << cnt << endl;
  for (int i = 0; i < N; i++) {
    cout << num.at(i) << endl;
  }
}
  
  
int main() {
  int N;
  cin >> N;
  vector<int> num(N);
  for (int i = 0; i < N; i++) {
    cin >> num.at(i);
  }

  shellSort(num, N);
}