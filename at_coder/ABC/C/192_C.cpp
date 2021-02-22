#include <bits/stdc++.h>
using namespace std;
 
void make_vec(int N, int K) {
  int smaller = 0, bigger = 0, expo, num;
  vector<int> number(10, 0);
  
  if( N!= 0) {
    for(int i = 0; i < 9; i++) {
      expo = 1;
      if(i != 0) {
        for(int j = 0; j < i; j++){
          expo *= 10;
        }
      }
      num = N / expo % 10;
      if(N / expo == 0) {
        break;
      }
      for(int j = 0; j < 10; j++){
        if(num == j) {
          number.at(j) += 1;
        }
      }
    }
    
    for(int i = 1; i < 10; i++) {
      if(number.at(i) != 0) {
        for(int j = 0; j < number.at(i); j++) {
          if(smaller == 0) {
            smaller = i;
          } else {
            smaller = smaller * 10 + i;
          }
        }
      }
    }
      
    for(int i = 9; i >= 0; i--) {
      if(number.at(i) != 0) {
        for(int j = 0; j < number.at(i); j++) {
          if(bigger == 0) {
            bigger = i;
          } else {
            bigger = bigger * 10 + i;
          }
        }
      }
    }
    
  }
 
  if(K != 0) {
    N = bigger - smaller;
    make_vec(N, K - 1);
  } else {
    cout << N << endl;
  }
 
}
 
int main() {
  int N, K;
  cin >> N >> K;
  
  make_vec(N, K);
}
#include <bits/stdc++.h>
using namespace std;

void make_vec(int N, int K) {
  int smaller = 0, bigger = 0, expo, num;
  vector<int> number(10, 0);
  
  if( N!= 0) {
    for(int i = 0; i < 9; i++) {
      expo = 1;
      if(i != 0) {
        for(int j = 0; j < i; j++){
          expo *= 10;
        }
      }
      num = N / expo % 10;
      if(N / expo == 0) {
        break;
      }
      for(int j = 0; j < 10; j++){
        if(num == j) {
          number.at(j) += 1;
        }
      }
    }
    
    for(int i = 1; i < 10; i++) {
      if(number.at(i) != 0) {
        for(int j = 0; j < number.at(i); j++) {
          if(smaller == 0) {
            smaller = i;
          } else {
            smaller = smaller * 10 + i;
          }
        }
      }
    }
      
    for(int i = 9; i >= 0; i--) {
      if(number.at(i) != 0) {
        for(int j = 0; j < number.at(i); j++) {
          if(bigger == 0) {
            bigger = i;
          } else {
            bigger = bigger * 10 + i;
          }
        }
      }
    }
    
  }

  if(K != 0) {
    N = bigger - smaller;
    make_vec(N, K - 1);
  } else {
    cout << N << endl;
  }

}

int main() {
  int N, K;
  cin >> N >> K;
  
  make_vec(N, K);
}
提出情報
提出日時