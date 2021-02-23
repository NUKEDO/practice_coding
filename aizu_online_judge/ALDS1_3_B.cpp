// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, quantum, num,current_time = 0;
  string str;
  cin >> n >> quantum;
  queue<string> process_name;
  queue<int> process_time;
              
  for (int i = 0; i < n; i++) {
    cin >> str >> num;
    process_name.push(str); 
    process_time.push(num);
  }
  
  while (process_name.size() > 0) {
    if(process_time.front() > quantum) {
      current_time += quantum;
      process_time.front() -= quantum;
      process_name.push( process_name.front() );
      process_name.pop();
      process_time.push( process_time.front() );
      process_time.pop();
    } else {
      current_time += process_time.front();
      cout << process_name.front() << " " << current_time << endl;
      process_name.pop();
      process_time.pop();
    }
  }
}