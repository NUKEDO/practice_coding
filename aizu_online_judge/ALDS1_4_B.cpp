// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja

#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &S, int num, int vec_start, int vec_end) {
  if(vec_start == vec_end || vec_start == vec_end - 1) {
    if(S.at(vec_start) == num || S.at(vec_end) == num) {
      return 1;
    } else {
      return 0;
    }
  }
  
  int check = (vec_start + vec_end) / 2;
  if(S.at(check) > num) {
    vec_end -= (vec_end - vec_start) / 2;
  } else if(S.at(check) < num) {
    vec_start += (vec_end - vec_start) / 2;
  } else if(S.at(check) == num) {
    return 1;
  }
  return binary_search(S, num, vec_start, vec_end);
}
  
int main() {
  int n, q;
  cin >> n;
  vector<int> S(n);
  for(int i = 0; i < n; i++) {
    cin >> S.at(i);
  }
  cin >> q;
  vector<int> T(q);
  for(int i = 0; i < q; i++) {
    cin >> T.at(i);
  }
  
  int sum = 0;
  for(int i = 0; i < q; i++) {
    sum += binary_search(S, T.at(i), 0, n - 1);
  }
  cout << sum << endl;
}