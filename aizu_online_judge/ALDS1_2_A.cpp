// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> A, int N) {
  int save, flag = 1, sum = 0;
  if ( N == 1) {
    cout << A.at(0) << endl;
  } else {
    while(flag == 1){
      flag = 0;
      for (int j = N - 1; j > 0; j--) {
        if( A.at(j) < A.at(j - 1) ) {
          save = A.at(j);
          A.at(j) = A.at(j - 1);
          A.at(j - 1) = save;
          flag = 1;
          sum += 1;
        }
      }
    }
    
    for (int i = 0; i < N; i++) {
      cout << A.at(i);
      if( i != N -1 ) {
        cout << " ";
      }
    }
    cout << endl;
  }
  cout << sum << endl;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  bubbleSort(A, N);
}
