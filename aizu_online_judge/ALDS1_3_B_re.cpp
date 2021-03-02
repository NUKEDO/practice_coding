// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B&lang=ja
// 螺旋本を見て解き方が間違ってたので作り直し

// 配列を循環させることでキュー型のデータとして用いる
#include <bits/stdc++.h>
using namespace std;

struct Process{
  string p_name; 
  int p_time;
};

//末尾に入れる
void enqueue(Process p_save, vector<Process> &p, int &tail, int n) {
  tail = (tail + 1) % n;
  p.at(tail) = p_save;
}

//先頭から取り出す
Process dequeue(vector<Process> &p, int &head, int n) {
  Process p_head = p.at(head);
  head = (head + 1) % n;
  return p_head;
}

int main() {
  int n, q, num, sum_time = 0;
  string str;
  cin >> n >> q;
  vector<Process> p(n + 1);
  Process p_save;

  for(int i = 0; i < n; i++) {
    cin >> str >> num;
    p.at(i).p_name = str;
    p.at(i).p_time = num;
  }
  
  int head = 0, tail = n - 1;
  while (head != tail) { //残り1個になるまで
    if(p.at(head).p_time > q) {
      p_save = dequeue(p, head, n);
      p_save.p_time -= q;
      sum_time += q;
      enqueue(p_save, p, tail, n);
    } else {
      sum_time += p.at(head).p_time;
      cout << p.at(head).p_name << " " << sum_time << endl;
      dequeue(p, head, n);
    }
  }
  sum_time += p.at(head).p_time;
  cout << p.at(head).p_name << " " << sum_time << endl;
}