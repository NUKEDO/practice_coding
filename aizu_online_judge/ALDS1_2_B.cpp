// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B&lang=ja

#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> A, int N) {
  for (int i = 0; i < N; i++) {
    cout << A.at(i);
    if( i != N - 1 ) {
      cout << " ";
    }
  }
  cout << endl;
}

vector<int> selectionSort(vector<int> A, int N) {
  int min_j, save, sum = 0;
  
  for( int i = 0; i < N - 1; i++ ) {
    min_j = i;
    for (int j = i + 1; j < N; j++ ) {
      if( A.at(j) < A.at(min_j) ) {
        min_j = j;
      }
    }
    if( min_j != i){
      save = A.at(i);
      A.at(i) = A.at(min_j);
      A.at(min_j) = save;
      sum += 1;
    }
  }

  A.at(N) = sum;
  return A;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  vector<int> comp(N + 1);
  comp = selectionSort(A, N);
  print_vec( comp, N);
  cout << comp.at(N) << endl;
}