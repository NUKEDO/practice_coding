#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;

void printA(vector<int> A) {
  for(int i = 0; i < A.size(); i++) {
    if(i) printf(" ");
    printf("%d", A.at(i));
  }
  printf("\n");
}

void printA2(vector<int> A) {
  for(int i = 0; i < n; i++) {
    printf("%d\n", A.at(i));
  }
}
/*
void insertionSort(vector<int> &A) {
  for(int i = 0; i < A.size(); i++) { //A.at(i)をソート済みの中に挿入する
    int save_i = i;
    for(int j = i - 1; j >= 0; j--) {
      if(A.at(i) < A.at(j)) {
        swap(A.at(i), A.at(j));
        cnt++;
        i--;
      } else { 
        break;
      }
    }
    i = save_i;
  }
}

vector<int> divideVec(vector<int> A, int g, int i) {
  vector<int> B;
  while (i < n) {
    B.push_back(A.at(i));
    i += g;
  }
  return B;
}

void insertionSortG(vector<int> &A, int g) {
  for(int i = 0; i < g; i++) { //g個の配列に分断する
    vector<int> B = divideVec(A, g, i);
    //テスト出力用
    //printf("testB: ");
    //printA(B);
    insertionSort(B); //Bをソートする
    for(int j = 0; j < B.size(); j++) {
      A.at(i + j * g) = B.at(j); //並べ替えたBをAに戻す
    }
  }
}
*/

void shellSort(vector<int> &A) {
  int m = 1;
  vector<int> G;
  do {
    G.push_back(m);
    m = 3 * m + 1; //3m+1での区切りが一番効率が良い
  } while(n > m); //n=1の時にもGが作成される
  reverse(G.begin(), G.end());
  
  printf("%d\n", G.size()); //1行目
  printA(G); //2行目
  
  
  for(int i = 0; i < G.size(); i++) {
    for(int j = 0; j < n; j += g) { //A.at(j)をソート済みの中に挿入する
      int save_j = j;
      
      //作成中
      //
      //
      //
      //
      for(int k = (ここが分からん); k >= 0; k -= g) {
        if(A.at(j) < A.at(k)) {
          swap(A.at(j), A.at(k));
          cnt++;
          j--;
        } else { 
          break;
        }
      }
      j = save_j;
    }
  }
  
  printf("%d\n", cnt); //3行目
  printA2(A); //4行目以降
}

int main() {
  scanf("%d\n", &n);
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &A.at(i));
  }
  
  shellSort(A);
}