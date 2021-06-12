#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int> > pic(8, vector<int>(8));

int checkDistance(vector<int> num) {
  int sum = 0;
  for(int i = 0; i < n; i++) {
    if(i == 0) {
      sum += pic.at(0).at(num.at(i));
    } else if(i == n - 1) {
      sum += pic.at(num.at(i - 1)).at(0);
    } else {
      sum += pic.at(num.at(i - 1)).at(num.at(i));
    }
  }
  if(sum == k) return 1;
  else return 0;
}

void printVec(vector<int> v) {
  for(int i = 0; i < v.size(); i++) {
    if(i) printf(" ");
    printf("%d", v.at(i));
  }
  printf("\n");
}

int main() {
  scanf("%d %d\n", &n, &k);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &pic.at(i).at(j));
    }
  }
  
  vector<int> num(n - 1);
  for(int i = 0; i < num.size(); i++) {
    num.at(i) = i + 1; //n=4の時 num={1,2,3}
  }
  
  int cnt = 0;
  do {
    //printVec(num);
    cnt += checkDistance(num);
  } while (next_permutation(num.begin(), num.end()));
  
  printf("%d\n", cnt);
}