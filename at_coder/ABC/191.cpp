
// A
#include <bits/stdc++.h>
using namespace std;

int main() {
  int V, T, S, D;
  cin >> V >> T >> S >> D;
  string str = "Yes";
  if (V * T <= D && V * S >= D) {
    str = "No";
  }
  cout << str << endl;
}


// B
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) == X) {
      A.at(i) = 0;
    }
  }
  
  int first_num = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) != 0) {
      if (first_num == 0){
        first_num++;
        cout << A.at(i);
      }
      else {
        cout << " " << A.at(i);
      }
    }
  }
  cout << endl;
}
