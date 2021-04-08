// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C&lang=ja
// 螺旋本を参考に作成

#include <bits/stdc++.h>
using namespace std;

int H = 0;

void maxHeapify(vector<int> &A, int u) {
  int l = u * 2, r = u * 2 + 1;
  int A_r = (r < A.size()) ? A.at(r) : INT_MIN;
  if(l < A.size() && A.at(l) > A.at(u) && A.at(l) >= A_r) {
    swap(A.at(l), A.at(u));
    maxHeapify(A, l);
  } else if(r < A.size() && A.at(r) > A.at(u) && A_r >= A.at(l)) {
    swap(A.at(r), A.at(u));
    maxHeapify(A, r);
  }
}

int extract(vector<int> &A) {
  int maxv = A.at(1);
  A.at(1) = A.at(H); //最大値の位置を最小値候補と交換
  H--;
  maxHeapify(A, 1);
  A.pop_back(); // 最後尾に最小値候補のコピーが来るので削除
  return maxv;
}

void increaseKey(vector<int> &A, int num) {
  if(num < A.at(H)) return;
  int i = H;
  while(i > 1 && A.at(i / 2) < A.at(i)) {
    swap(A.at(i), A.at(i / 2));
    i = i / 2;
  }
}

void insert(vector<int> &A, int num) {
  H++;
  A.push_back(num);
  increaseKey(A, num);
}

int main() {
  int num;
  string str;
  vector<int> A;
  A.push_back(INT_MIN); //A.at(0)を埋める
  while(cin >> str) {
    if(str == "end") break;
    if(str == "insert") {
      scanf("%d", &num);
      insert(A, num);
    } else if(str == "extract") {
      printf("%d\n", extract(A));
    }
    
    /* //配列チェック用
    for(int i = 1; i < A.size(); i++) cout << A.at(i) << " ";
    cout << endl;
    */
  }
}