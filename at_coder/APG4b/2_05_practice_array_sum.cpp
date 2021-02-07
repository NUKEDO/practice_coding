#include <bits/stdc++.h>
using namespace std;
int array_sum(vector<int> &a, int i) {
  /*
  a = (0, 3, 9, 1, 5)の時
  y = 0 + (3,9,1,5)
    = 0 + 3 + (9,1,5)
  */
  if (i == a.size() - 1) {
    return a.at(i);
  }
  // 解答例のベースケースでは i == a.size()の時に return 0;

  
  int s = a.at(i) + array_sum(a, i+1);
  return s;
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  cout << array_sum(a, 0) << endl;   // 0 + 3 + 9 + 1 + 5 = 18
}