// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int current_height = 0, test = 0;
  char c;
  stack<int> st1;
  stack<pair<int, int>> st2;
  
  int num, culc, j = 0;
  while (cin >> c) {
    if (c == '\\') {
      st1.push(j);      
    } else if (c == '/') {
      if(st1.size() > 0) { // 対応する'\'が存在すれば実行できる
        if(st2.size() == 0 || ( st2.size() > 0 && st1.top() > st2.top().second) ) {
          num = st1.top();
          culc = j - num;
          st1.pop();
        } else if(st2.size() > 0 && st1.top() < st2.top().second) {
          num = st1.top();
          culc = j - num + st2.top().first;
          st1.pop();
          st2.pop();
          while (st2.size() > 0 && num < st2.top().second) {
            culc += st2.top().first;
            st2.pop();
          }
        }
        st2.push( make_pair(culc, num) );
      }
      
    } // c=='/' end
    j++;
  }
  
  int sum1 = 0, sum2 = 0, size_num = st2.size();
  vector<int> save( size_num );
  j = 0;
  while (st2.size() > 0) {
    sum1++;
    sum2 += st2.top().first;
    save.at(j) = st2.top().first;
    j++;
    st2.pop();
  }
  cout << sum2 << endl << sum1;
  if(size_num > 0) {
    cout << " ";
    for(int i = size_num - 1; i >= 0; i--) {
      cout << save.at(i);
      if(i != 0) {
        cout << " ";
      }
    }
  }
  cout << endl;
}