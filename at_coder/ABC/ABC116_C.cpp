#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0; // cnt:水やり回数
vector<int> f(100);

void printVec(vector<int> v) { // v = {1, 2, 3, 4}の時
  for(int i = 0; i < n; i++) {
    if(i) printf(" ");
    printf("%d", v.at(i));
  }
  printf("\n"); // "1 2 3 4"と出力されて改行される
}

void watering() {
  int save_min, save_i, save_j, check = 0;
  for(int i = 0; i < n; i++) {
    if(f.at(i) != 0) {
      check = 1;
      save_i = i;
      save_j = i; //i==n-1の時用
      save_min = f.at(i); //同上
      int j = i;
      while(j < n) { // for(int j = i; j < n; j++) でも可
        save_min = min(save_min, f.at(j));
        if(j + 1 == n || f.at(j + 1) == 0) {
          save_j = j; 
          break;
        } // else if(f.at(j + 1) != 0)
        j++;
      }
      break;
    }
  }
  if(check) { //(check==1) == (f.at(i)に0じゃないものが存在した) 
    cnt += save_min;
    for(int i = save_i; i <= save_j; i++) {
      f.at(i) -= save_min;
    }
  
    //printf("%d: ", cnt); //テスト出力用
    //printVec(f);

    watering();
  }
}

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &f.at(i));
  }
  
  watering();
  
  printf("%d\n", cnt);
}