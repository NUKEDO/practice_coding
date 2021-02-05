// https://atcoder.jp/contests/apg4b/tasks/APG4b_aa
// https://atcoder.jp/contests/apg4b/tasks/APG4b_bz

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a;
  cin >> N;
  priority_queue<int> num;
  for (int i = 0; i < N; i++) {
    cin >> a;
    num.push(a);
  }
  
  int memo = num.top(), sum = 0; // 暫定最大値・出現回数
  pair<int, int> max(0, 0); // 最大の値・出現回数
  for (int i = 0; i < N; i++) {
    if (num.top() == memo) {
      sum += 1;
      if (sum >= max.second) {
        max.first = memo;
        max.second = sum;
      }
    }
    else { // num.top() != memo
      memo = num.top();
      sum = 1;
    }
    num.pop();
  }
  cout << max.first << " " << max.second << endl;
}