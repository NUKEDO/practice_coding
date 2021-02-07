/*
   ///////////////////
   ///未完成・動かない///
   ///////////////////
*/


#include <bits/stdc++.h>
using namespace std;
vector<int> reverse_array(vector<int> &a, vector<int> &b, int i) {
  /*
  a=(1,2,3,4,5)の時
  b=(5) + (1,2,3,4)
   =(5,4) + (1,2,3)
  */
  if (b.size() == a.size()) {
    vector<int> empty(0);
    return empty;
  }
  
  //b.push_back(a.at(a.size() - i - 1));
  int x = a.at(4);
  b.push_back(4);
  // reverse_array(a, b, i + 1);
  return b;
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  
  vector<int> c = reverse_array(a, b, 0);
  
  for (int i = 0; i < N; i++) {
    cout << c.at(i) << endl;
  }
}